//
// Created by terry on 10/14/20.
//

#ifndef GITME_GITME_TYPE_H
#define GITME_GITME_TYPE_H

#include <cstring>
#include <string>
#include <stdexcept>
#include <map>

#define NC "\033[0m"
#define SP " "
#define ORANGE "\033[0;33m"
#define LIGHT_BLUE "\033[1;34m"

typedef std::map<std::string, std::string> args_table_type;

std::string exec(const char *cmd);

std::string exec(std::string const &cmd);

class arg {
public:
    std::string name;
    std::string value;
    const char *tip;
    bool (*validate)(std::string const &);

public:
    arg(const char *name, const char *value, const char *tip, bool (*validate)(std::string const &) = arg::void_validate)
            :
            name(name), value(value), tip(tip), validate(validate){}

    static bool void_validate(std::string const &value){
        return !value.empty();
    }
    static bool optimistic_validate(std::string const &value){
        return true;
    }
};

#endif //GITME_GITME_TYPE_H
