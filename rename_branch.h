//
// Created by terry on 10/13/20.
//

#ifndef GITME_RENAME_BRANCH_H
#define GITME_RENAME_BRANCH_H

#include <string>
#include <iostream>

#include "gitme_type.h"

namespace {
    bool bool_validate(std::string const &value){
        return !(value.empty() || (value != "true" && value != "false"));
    }
    bool mode_validate(std::string const &value){
        return !(value.empty() || (value != "on" && value != "off"));
    }
}

int rename_branch(const args_table_type &args_table) {
    arg args[] = {
            {"-old-branch",       "",
                                               "optional parameter:" SP LIGHT_GREEN
                                               "old-branch " NC SP
                                               "the old branch to be renamed <default: " LIGHT_PURPLE"current git branch" NC">",
                    arg::optimistic_validate},
            {"-new-name",         "",
                                               "parameter required:" SP ORANGE
                                               "new-name   " NC SP
                                               "the new branch name"
            },
            {"-force",            "false",
                                               "optional parameter:" SP LIGHT_GREEN
                                               "force      " NC SP
                                               "Should it be forced to rename if a branch with the same name as the new name already exists?"
                                               "(" LIGHT_BLUE"true/false" NC") <default: " LIGHT_PURPLE"false" NC">",
                    bool_validate},
            {HELP,                "not-empty", "",
                    arg::optimistic_validate,
                    true},
            {"-" STRICT_MODE_RAW, "on",
                                               "mode parameter:    " SP LIGHT_RED
                                               STRICT_MODE_RAW NC SP
                                               "if on, all the optional parameters are mandatory"
                                               "(" LIGHT_BLUE"on/off" NC") <default: " LIGHT_PURPLE"on" NC">",
                    mode_validate,
                    true}
    };
    for (auto &i : args_table){
        for (auto &j : args){
            if (j.name == i.first) {
                j.value = i.second;
                j.edited = true;
                break;
            }
        }
    }
    if (args[3].value.empty()){
        std::cout << std::endl << "Usage:" << std::endl << std::endl;
        for (auto &i : args){
            if (i.name != HELP)
                std::cout << i.tip << std::endl << std::endl;
        }
        return 0;
    }
    if (!args[4].validate(args[4].value)){
        std::cout << LIGHT_RED << "error: " << NC << args[4].tip << std::endl;
        return 1;
    }
    bool strict_mode = (args[4].value == "on");
    bool wrong = false;
    for (auto &i : args){
        if ((!i.validate(i.value)) || (strict_mode && (!i.edited))) {
            std::cout << LIGHT_RED << "error: " << NC << i.tip << std::endl;
            wrong = true;
        }
    }
    if (wrong) return 1;
    const char *force_flag;
    if (args[2].value == "true")
        force_flag = "-M";
    else
        force_flag = "-m";
    std::string res;
    res.append("git branch ").append(force_flag).append(" ").append(args[0].value).append(" ").append(args[1].value);
    int res_code;
    std::cout << exec(res, res_code);
    return res_code;
}

#endif //GITME_RENAME_BRANCH_H
