//
// Created by terry on 10/15/20.
//

#include <iostream>
#include "gitme_type.h"

std::string exec(const char *cmd, int &exit_code) {
    char c;
    std::string result;
    FILE *pipe = popen(((std::string)(cmd)).append(" 2>&1").c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (c = fgetc(pipe), c != EOF) {
        result.append(1, c);
    }
    exit_code = pclose(pipe);
    return std::move(result);
}

std::string exec(std::string const &cmd, int &exit_code) {
    char c;
    std::string result;
    FILE *pipe = popen(((std::string)(cmd)).append(" 2>&1").c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (c = fgetc(pipe), c != EOF) {
        result.append(1, c);
    }
    exit_code = pclose(pipe);
    return std::move(result);
}

bool in_git_repos(){
    return ( exec("git rev-parse --is-inside-work-tree").find("true") != std::string::npos );
}

/**
 * newline and tab will not be escaped
 */
std::string& escape_utf8(std::string &text){
    std::string new_text;
    for(auto i = text.begin(); i != text.end(); i++){
        switch (*i) {
            case '`':
                new_text.append("\\").append("`");
                break;
            case '~':
                new_text.append("\\").append("~");
                break;
            case '!':
                new_text.append("\\").append("!");
                break;
            case '@':
                new_text.append("\\").append("@");
                break;
            case '#':
                new_text.append("\\").append("#");
                break;
            case '$':
                new_text.append("\\").append("$");
                break;
            case '&':
                new_text.append("\\").append("&");
                break;
            case '*':
                new_text.append("\\").append("*");
                break;
            case '(':
                new_text.append("\\").append("(");
                break;
            case ')':
                new_text.append("\\").append(")");
                break;
            case '+':
                new_text.append("\\").append("+");
                break;
            case '\\':
                new_text.append("\\").append("\\");
                break;
            case '|':
                new_text.append("\\").append("|");
                break;
            case ']':
                new_text.append("\\").append("]");
                break;
            case '}':
                new_text.append("\\").append("}");
                break;
            case '[':
                new_text.append("\\").append("[");
                break;
            case '{':
                new_text.append("\\").append("{");
                break;
            case ';':
                new_text.append("\\").append(";");
                break;
            case '\'':
                new_text.append("\\").append("'");
                break;
            case '"':
                new_text.append("\\").append("\"");
                break;
            case '?':
                new_text.append("\\").append("?");
                break;
            case '.':
                new_text.append("\\").append(".");
                break;
            case '>':
                new_text.append("\\").append(">");
                break;
            case ',':
                new_text.append("\\").append(",");
                break;
            case '<':
                new_text.append("\\").append("<");
                break;
            case ' ':
                new_text.append("\\").append(" ");
                break;


            case '%':
                new_text.append("%");
                break;
            case '^':
                new_text.append("^");
                break;
            case '-':
                new_text.append("-");
                break;
            case '_':
                new_text.append("_");
                break;
            case '=':
                new_text.append("=");
                break;
            case ':':
                new_text.append(":");
                break;
            case '/':
                new_text.append("/");
                break;


            default:
                new_text.append(1, *i);
        }
    }
    text = std::move(new_text);
    return text;
}

/**
 * replace the first occurrence of color-config-code with a space
 */
std::string& remove_color(std::string &text){
    text.replace(text.find(GIT_COLOR), std::strlen(GIT_COLOR), " ");
    return text;
}

int before(const args_table_type &args_table, arg *args, int arg_num, int help_index, int strict_mode_index){
    // ====== Show help / Validate parameters
    for (auto &i : args_table){// read parameters
        for (int j_ = 0; j_ < arg_num; j_++){
            auto &j = args[j_];
            if (j.name == i.first) {
                j.value = ((i.second.empty())?(j.void_value):(i.second));
                j.edited = true;
                break;
            }
        }
    }
    if (args[help_index].value.empty()){// show help
        std::cout << std::endl << "Usage:" << std::endl << std::endl;
        for (int i_ = 0; i_ < arg_num; i_++){
            auto &i = args[i_];
            if (i_ != help_index)
                std::cout << i.tip << std::endl << std::endl;
        }
        return 0;
    }
    if (!args[strict_mode_index].validate(args[strict_mode_index].value)){// validate strict-mode parameter
        std::cout << LIGHT_RED << "error: " << NC << args[strict_mode_index].tip << std::endl;
        return 1;
    }
    bool strict_mode = (args[strict_mode_index].value == "on");
    bool wrong = false;
    for (int i_ = 0; i_ < arg_num; i_++){// validate parameters
        auto &i = args[i_];
        if ((!i.validate(i.value)) || (strict_mode && (!i.edited))) {
            std::cout << LIGHT_RED << "error: " << NC << i.tip << std::endl;
            wrong = true;
        }
    }
    if (wrong) {
        std::cout << "(" << LIGHT_RED << "strict mode: " << LIGHT_BLUE << args[strict_mode_index].value << NC << ")" << NC << std::endl;
        return 1;
    }
    return NORMAL;
}

int after(std::string const &git_cmd){
    // ====== Execute git command
    int res_code;
    std::string no_color_git_cmd(git_cmd);
    std::cout << YELLOW << "the git command is => " << NC << remove_color(no_color_git_cmd) << std::endl;
    std::cout << LIGHT_BLUE << "the git command output: " << NC << std::endl << std::endl;
    std::cout << exec(git_cmd, res_code) << std::endl;
    return res_code;
}

bool arg::void_validate(std::string const &value){
    return !value.empty();
}
bool arg::optimistic_validate(std::string const &value){
    return true;
}
bool arg::bool_validate(std::string const &value){
    return !(value.empty() || (value != "true" && value != "false"));
}
bool arg::mode_validate(std::string const &value){
    return !(value.empty() || (value != "on" && value != "off"));
}

int exec_exit_code_ = 0;