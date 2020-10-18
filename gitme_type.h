//
// Created by terry on 10/14/20.
//

#ifndef GITME_GITME_TYPE_H
#define GITME_GITME_TYPE_H

#include <cstring>
#include <string>
#include <stdexcept>
#include <map>

#define GITME_VERSION "0.1"
#define HELP "-help"
#define STRICT_MODE_RAW "strict-mode"
#define NC "\033[0m"
#define SP " "
#define ORANGE "\033[0;33m"
#define GREEN "\033[0;32m"
#define LIGHT_GREEN "\033[1;32m"
#define LIGHT_BLUE "\033[1;34m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define RED "\033[0;31m"
#define LIGHT_RED "\033[1;31m"
#define GRAY "\033[0;37m"

typedef std::map<std::string, std::string> args_table_type;

extern int exec_exit_code_;

std::string exec(const char *cmd, int &exit_code = exec_exit_code_);

std::string exec(std::string const &cmd, int &exit_code = exec_exit_code_);

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

    static bool void_validate(std::string const &value);
    static bool optimistic_validate(std::string const &value);
};

#endif //GITME_GITME_TYPE_H
