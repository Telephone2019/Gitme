//
// Created by yjt on 10/16/20.
//

#ifndef GITME_SHOW_LOCAL_BRANCHES_H
#define GITME_SHOW_LOCAL_BRANCHES_H
#include <string>
#include <iostream>

#include "gitme_type.h"

int show_local_branches(const args_table_type &args_table){//wrong parameter such as: XXX XXX: should be banned but -XXX or -xxx: need to show useful commands
    arg args[] = {
            {"-verbose",          "false",
                                               "optional parameter:" SP LIGHT_GREEN
                                               "verbose    " NC SP
                                               "Show details of your local branches"
                                               "(" LIGHT_BLUE"true/false" NC") <default: " LIGHT_PURPLE"false" NC">",
                    arg::bool_validate},
            {HELP,                "not-empty", "",
                    arg::optimistic_validate,
                    true},
            {"-" STRICT_MODE_RAW, "on",
                                               "mode parameter:    " SP LIGHT_RED
                                               STRICT_MODE_RAW NC SP
                                               "if on, all the optional parameters are mandatory"
                                               "(" LIGHT_BLUE"on/off" NC") <default: " LIGHT_PURPLE"on" NC">",
                    arg::mode_validate,
                    true}
    };
    // ====== Show help / Validate parameters
    for (auto &i : args_table) {// read parameters
        for (auto &j : args) {
            if (i.first == j.name) {
                j.value = i.second;
                j.edited = true;
                break;
            }
        }
    }
    if (args[1].value.empty()) {// show help
        std::cout << std::endl << "Usage:" << std::endl << std::endl;
        for (auto &i : args) {
            if (i.name != HELP)
                std::cout << i.tip << std::endl << std::endl;
        }
        return 0;
    }
    if (!args[2].validate(args[2].value)){// validate strict-mode parameter
        std::cout << LIGHT_RED << "error: " << NC << args[2].tip << std::endl;
        return 1;
    }
    bool strict_mode = (args[2].value == "on");
    bool wrong = false;
    for (auto &i : args){
        if ((!i.validate(i.value)) || (strict_mode && (!i.edited))) {
            std::cout << LIGHT_RED << "error: " << NC << i.tip << std::endl;
            wrong = true;
        }
    }
    if (wrong) {
        std::cout << "(" << LIGHT_RED << "strict mode: " << LIGHT_BLUE << args[2].value << NC << ")" << NC << std::endl;
        return 1;
    }
    // ====== Generate git command
    std::string res;
    res.append("git branch");
    if(args[0].value=="true"){
        res.append(" -vv");
    }
    // ====== Execute git command
    int res_code;
    std::cout << YELLOW << "the git command is => " << NC << res << std::endl;
    std::cout << LIGHT_BLUE << "the git command output: " << NC << std::endl;
    std::cout << exec(res, res_code);
    return res_code;
}

#endif //GITME_SHOW_LOCAL_BRANCHES_H
