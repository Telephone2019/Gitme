#include <iostream>
#include <map>
#include <unistd.h>

#include "gitme_type.h"
void regis_telephone();
void regis_tyj();

std::string first_arg;
std::string second_arg;
args_table_type other_args;
std::map<std::string, int(*)(const args_table_type &)> table;
char cwd[1024] = {0};

void clean(){
    first_arg.clear();
    second_arg.clear();
    other_args.clear();
}

std::pair<bool, std::pair<std::string, std::string>> parse(const std::string &text){
    std::pair<bool, std::pair<std::string, std::string>> res(false, (std::pair<std::string, std::string>){"", ""});
    int index = text.find_first_of(':');
    if (index == std::string::npos)
        return std::move(res);
    res.first = true;
    if (index > 0)
        res.second.first += text.substr(0, index);
    if (index < text.length() - 1)
        res.second.second += text.substr(index + 1, text.length() - 1 - index);
    return std::move(res);
}

void regis(){
    regis_telephone();
    regis_tyj();
}

inline void get_cwd(){
    getcwd(cwd, sizeof(cwd));
}

void init(){
    regis();
    clean();
    get_cwd();
}

void show_usage(){
    char usage[] = "a subcommand required: (one of these)";
    std::cout << usage << std::endl;
    std::cout << ORANGE;
    for (auto &i : table){
        std::cout << i.first << std::endl;
    }
    std::cout << NC;
}

int main(int argc, char **argv) {
    init();

    first_arg += argv[0];
    if (argc >= 2)
        second_arg += argv[1];
    for (int i = 2; i < argc; ++i) {
        auto arg = std::move(parse(argv[i]));
        if (arg.first)
            other_args.insert(arg.second);
    }

    std::string git_res = std::move(exec("git --version"));
    if (git_res.find("version") == std::string::npos) {
        std::cout << "error: git not found" << std::endl;
        return 1;
    }

    for (auto &i : table) {
        if (i.first == second_arg)
            return i.second(other_args);
    }
    show_usage();
    return 1;
}
