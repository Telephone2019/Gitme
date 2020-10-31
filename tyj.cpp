//
// Created by terry on 10/15/20.
//

#include <map>

#include "gitme_type.h"
#include "show_local_branches.h"
#include "commit.h"

extern std::map<std::string, int(*)(const args_table_type &)> table;

void regis_tyj(){
    table["show-local-branches"] = show_local_branches;
    table["commit"] = commit;
}