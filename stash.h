//
// Created by yjt on 10/20/20.
//

#ifndef GITME_STASH_H
#define GITME_STASH_H
#include <string>
#include <iostream>

#include "gitme_type.h"
int stash(const args_table_type &args_table){
    arg args[] = {
            {
                    "-save-with-message", "",          "",
                                                           "optional parameter:" SP LIGHT_GREEN
                                                           "with-message    " NC SP
                                                           "Leave a message to distinguish this commit,Not allowed to be empty"
            },
            {
                    "-list",              "false",     "true" "optional parameter:" SP LIGHT_GREEN
                                                       "list             " NC SP
                                                       "Show all saved list tin the stash"
                                                       "(" LIGHT_BLUE"true/false" NC") <default: " LIGHT_PURPLE"false" NC">"
                                                       SP"[-list equals to -list:true]",
                                                           arg::bool_validate
            },
            {
                    "-clear",             "false",     "true" "optional parameter:" SP LIGHT_GREEN
                                                       "list             " NC SP
                                                       "Delete all saved list tin the stash"
                                                       "(" LIGHT_BLUE"true/false" NC") <default: " LIGHT_PURPLE"false" NC">"
                                                       SP"[-clear equals to -clear:true]",
                                                           arg::bool_validate
            },
            {
                    "-show",              "",          "optional parameter:" SP LIGHT_GREEN
                                                       "show             " NC SP
                                                       "Shows what changes have been made by default"
                                                       "(" LIGHT_BLUE"stash@{$num}" NC") <default: " LIGHT_PURPLE"stash@{0}" NC">"
                                                       SP"[-list equals to -list:stash@{0}",
            },
            {
                    "-apply",             "",          "", "optional parameter:" SP LIGHT_GREEN
                                                           "apply             " NC SP
                                                           "Apply a storage, but will not delete the storage from the storage list"
                                                           "(" LIGHT_BLUE"stash@{$num}" NC") <default: " LIGHT_PURPLE"stash@{0}" NC">"
                                                           SP"[-apply equals to -apply:stash@{0}",

            },
            {
                    "-pop",               "",          "", "optional parameter:" SP LIGHT_GREEN
                                                           "pop             " NC SP
                                                           "Apply a storage, delete the storage from the storage list"
                                                           "(" LIGHT_BLUE"stash@{$num}" NC") <default: " LIGHT_PURPLE"stash@{0}" NC">"
                                                           SP"[-pop equals to -pop:stash@{0}",
            },
            {
                    "drop",               "",          "", "optional parameter:" SP LIGHT_GREEN
                                                           "drop             " NC SP
                                                           "Delete the storage from the storage list"
                                                           "(" LIGHT_BLUE"stash@{$num}" NC") <default: " LIGHT_PURPLE"stash@{0}" NC">"
                                                           SP"[-drop equals to -drop:stash@{0}",
            },
            {HELP,                        "not-empty", "", "",
                    arg::optimistic_validate,
                    true},
            {       "-" STRICT_MODE_RAW,  "on",        "on",
                                                           "mode parameter:    " SP LIGHT_RED
                                                           STRICT_MODE_RAW NC SP
                                                           "if on, all the optional parameters are mandatory"
                                                           "(" LIGHT_BLUE"on/off" NC") <default: " LIGHT_PURPLE"on" NC">"
                                                           SP"[-" STRICT_MODE_RAW " equals to -" STRICT_MODE_RAW ":on]",
                    arg::mode_validate,
                    true}
    };
    PROCESS(args, args_table, 6,7 );
    std::string res;
    res.append("git" GIT_COLOR "stash ");
    if(!args[0].value.empty())
        res.append("save ").append(escape_utf8(args[0].value));
    if(args[1].value=="true")
        res.append("list");
    if(args[2].value=="true")
        res.append("clear");
    for(int i=3,i < args.length(),i++){
        if(!args[i].value.empty()){
            res.append(args[i].name.substr(1)).append(" ").append(args[i].value);
            break;
        }
    }
    EXE_GIT(res)
}
#endif //GITME_STASH_H
