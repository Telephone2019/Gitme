//
// Created by yjt on 10/31/20.
//

#ifndef GITME_MERGE_H
#define GITME_MERGE_H
#include <string>
#include <iostream>

#include "gitme_type.h"
int commit(const args_table_type &args_table) {
    arg args[] = {
            {
                    "-current-branch",           "",          "", "parameter required:" SP ORANGE
                                                                  "current-branch   " NC SP
                                                                  "merge the branch you specify with current branch and automatically make a new commit"
            },
            {
                    "-current-branch-no-commit", "",          "", "parameter required:" SP ORANGE
                                                                  "current-branch   " NC SP
                                                                  "merge the branch you specify with current branch but not make a new commit"
            },
            {
                    "-ohther-branch",            "",          "", "parameter required:" SP ORANGE
                                                                  "other-branch   " NC SP
                                                                  "At the top of the current branch, merge the two branches you specify"
            },
            {HELP,                               "not-empty", "", "",
                    arg::optimistic_validate,
                    true},
            {       "-" STRICT_MODE_RAW,         "on",        "on",
                                                                  "mode parameter:    " SP LIGHT_RED
                                                                  STRICT_MODE_RAW NC SP
                                                                  "if on, all the optional parameters are mandatory"
                                                                  "(" LIGHT_BLUE"on/off" NC") <default: " LIGHT_PURPLE"on" NC">"
                                                                  SP"[-" STRICT_MODE_RAW " equals to -" STRICT_MODE_RAW ":on]",
                    arg::mode_validate,
                    true}
    };
    PROCESS(args, args_table, 3, 4)
    std::string res;
    res.append("git" GIT_COLOR "merge ");
    if(!args[0].value.empty())
        res.append(args[0].value);
    if(!args[1].value.empty())
        res.append("--no-commit ").append(args[1].value);
    if(!args[2].value.empty())
        res.append(escape_utf8(args[2].value));
    EXE_GIT(res)
}
#endif //GITME_MERGE_H
