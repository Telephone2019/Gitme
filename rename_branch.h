//
// Created by terry on 10/13/20.
//

#ifndef GITME_RENAME_BRANCH_H
#define GITME_RENAME_BRANCH_H

#include <string>

#include "gitme_type.h"

int rename_branch(const args_table_type &args_table){
    std::cout << "rename_branch() called" << std::endl;
    arg args[] = {
            {"-old-branch", "", "parameter required:" SP ORANGE"old-branch" NC SP"the old branch to be renamed"},
            {"-new-name", "", "parameter required:" SP ORANGE"new-name" NC SP"the new branch name"},
            {"-force", "", "parameter required:" SP ORANGE"force" NC SP"Should it be forced to rename if a branch with the same name as the new name already exists?(" LIGHT_BLUE"true/false" NC")"}
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
        if (i.value.empty()) {
            std::cout << i.tip << std::endl;
            wrong = true;
        }
    }
    if (wrong) return 1;
    return 0;
}

#endif //GITME_RENAME_BRANCH_H
