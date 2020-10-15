//
// Created by terry on 10/13/20.
//

#ifndef GITME_RENAME_BRANCH_H
#define GITME_RENAME_BRANCH_H

#include <string>
#include <iostream>

#include "gitme_type.h"

namespace {
    bool validate(std::string const &value){
        return !(value.empty() || (value != "true" && value != "false"));
    }
}

int rename_branch(const args_table_type &args_table){
    arg args[] = {
            {"-old-branch", "", "parameter required:" SP ORANGE"old-branch" NC SP"the old branch to be renamed", arg::optimistic_validate},
            {"-new-name", "", "parameter required:" SP ORANGE"new-name" NC SP"the new branch name"},
            {"-force", "false", "parameter required:" SP ORANGE"force" NC SP"Should it be forced to rename if a branch with the same name as the new name already exists?(" LIGHT_BLUE"true/false" NC")", validate}
    };
    for (auto &i : args_table){
        for (auto &j : args){
            if (j.name == i.first) {
                j.value = i.second;
                break;
            }
        }
    }
    bool wrong = false;
    for (auto &i : args){
        if (!i.validate(i.value)) {
            std::cout << i.tip << std::endl;
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
    std::cout << exec("gitme", res_code);
    return res_code;
}

#endif //GITME_RENAME_BRANCH_H
