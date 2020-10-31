//
// Created by yjt on 10/20/20.
//

#ifndef GITME_COMMIT_H
#define GITME_COMMIT_H
#include <string>
#include <iostream>

#include "gitme_type.h"
int commit(const args_table_type &args_table){
    arg args[] = {
            {
                    "-with-message",      "",          "",
                                                           "optional parameter:" SP LIGHT_GREEN
                                                           "with-message     " NC SP
                                                           "Leave a message to distinguish this commit and it's not allowed to be empty",
                    arg::optimistic_validate},
            {
                    "-add-before-commit", "false",     "true",
                                                           "optional parameter:" SP LIGHT_GREEN
                                                           "add-before-commit" NC SP
                                                           "Submit all files that have been modified or deleted in the tracked files to the local warehouse, "
                                                           "even if they are not added to the staging area through git add"
                                                           "(" LIGHT_BLUE"true/false" NC") <default: " LIGHT_PURPLE"false" NC">"
                                                           SP"[-add-before-commit equals to -add-before-commit:true]",
                    arg::bool_validate},
            {
                    "-temporary-config",  "",          "",
                                                           "optional parameter:" SP LIGHT_GREEN
                                                           "temporary-config " NC SP
                                                           "use the specified git config when commit",
                    arg::optimistic_validate},
            {HELP,                        "not-empty", "", "",
                    arg::optimistic_validate,
                    true},
            {       "-" STRICT_MODE_RAW,  "on",        "on",
                                                           "mode parameter:    " SP LIGHT_RED
                                                           STRICT_MODE_RAW SP  SP  SP  SP  SP  SP NC SP
                                                           "if on, all the optional parameters are mandatory"
                                                           "(" LIGHT_BLUE"on/off" NC") <default: " LIGHT_PURPLE"on" NC">"
                                                           SP"[-" STRICT_MODE_RAW " equals to -" STRICT_MODE_RAW ":on]",
                    arg::mode_validate,
                    true}
    };
    PROCESS(args, args_table, 3, 4)
    std::string res;
    if(!args[2].value.empty())
        res.append("git" GIT_COLOR).append(" -c " + escape_utf8(args[2].value)).append( " commit");
    else
        res.append("git" GIT_COLOR "commit");
    if(args[1].value=="true"){
        res.append(" -a");
    }
    if(!args[0].value.empty())
        res.append(" -m ").append(escape_utf8(args[0].value));
    EXE_GIT(res)
}
#endif //GITME_COMMIT_H
