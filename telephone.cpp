//
// Created by terry on 10/15/20.
//

#include <map>

#include "gitme_type.h"
#include "rename_branch.h"

extern std::map<std::string, int(*)(const args_table_type &)> table;

void regis_telephone(){
    table["rename-branch"] = rename_branch;
}