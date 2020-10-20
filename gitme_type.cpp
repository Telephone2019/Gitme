//
// Created by terry on 10/15/20.
//

#include <iostream>
#include "gitme_type.h"

std::string exec(const char *cmd, int &exit_code) {
    char c;
    std::string result;
    FILE *pipe = popen(cmd, "r");
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
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (c = fgetc(pipe), c != EOF) {
        result.append(1, c);
    }
    exit_code = pclose(pipe);
    return std::move(result);
}

int before(const args_table_type &args_table, arg *args, int arg_num, int help_index, int strict_mode_index){
    // ====== Show help / Validate parameters
    for (auto &i : args_table){// read parameters
        for (int j_ = 0; j_ < arg_num; j_++){
            auto &j = args[j_];
            if (j.name == i.first) {
                j.value = i.second;
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
    std::cout << YELLOW << "the git command is => " << NC << git_cmd << std::endl;
    std::cout << LIGHT_BLUE << "the git command output: " << NC << std::endl;
    std::cout << exec(git_cmd, res_code);
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