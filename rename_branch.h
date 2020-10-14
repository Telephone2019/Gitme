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
            {"-old-branch", "", "parameter required: " "\033[1;33m" "old-branch" "\033[0m" " " "the old branch to be renamed"},
            {"-new-name", "", "parameter required: " "\033[1;33m" "new-name" "\033[0m" " " "the new branch name"},
            {"-force", "", "parameter required: " "\033[1;33m" "force" "\033[0m" " "
                                                                                 "Should it be forced to rename if a branch with the same name as the new name already exists?(" "\033[0;34m" "true/false" "\033[0m" ")"}
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
