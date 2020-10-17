//
// Created by yjt on 10/16/20.
//

#ifndef GITME_SHOW_BRANCHES_H
#define GITME_SHOW_BRANCHES_H
#include <string>
#include <iostream>

#include "gitme_type.h"

int show_local_branches(const args_table_type &args_table){//wrong parameter such as: XXX XXX: should be banned but -XXX or -xxx: need to show useful commands
    arg args[] = {
            {"-verbose","false",""},
            {HELP,"non",SP ORANGE"-verbose" NC SP "Show details of branches" }
    };
    for (auto &i : args_table) {
        for (auto &j : args) {
            if (i.first == j.name) {
                j.value = i.second;
                break;
            }
        }
    }

    if(args[1].value.empty()){
        std::cout << args[1].tip << std::endl;
        return 0;
    }
    std::string res;
    res.append("git branch");
    if(args[0].value.empty()){
        res.append(" ").append("-vv");
    }

    int res_code;
    std::cout << exec(res,res_code);
}

#endif //GITME_SHOW_BRANCHES_H
