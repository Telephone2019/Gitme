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
    PROCESS(args, args_table, 1, 2)
    // ====== Generate git command
    std::string res;
    res.append("git" GIT_COLOR "branch");
    if(args[0].value=="true"){
        res.append(SP"-vv");
    }
    // ===========================
    EXE_GIT(res)
}

#endif //GITME_SHOW_LOCAL_BRANCHES_H
