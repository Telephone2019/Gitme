//
// Created by terry on 10/14/20.
//

#ifndef GITME_GITME_TYPE_H
#define GITME_GITME_TYPE_H

#include <cstring>
#include <string>
#include <stdexcept>
#include <map>

#define NORMAL 2
#define GITME_VERSION "0.1"
#define HELP "-help"
#define STRICT_MODE_RAW "strict-mode"
#define GIT_COLOR " -c color.ui=always "
#define TIP_COLOR YELLOW
#define NC "\033[0m"
#define SP " "
#define ORANGE "\033[0;33m"
#define YELLOW "\033[1;33m"
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

#define PROCESS(ARG_ARRAY,ARG_TABLE,HELP_INDEX,STRICT_MODE_INDEX)  \
int process_res_telephone__ = before(ARG_TABLE, ARG_ARRAY, sizeof(ARG_ARRAY) / sizeof(arg), HELP_INDEX, STRICT_MODE_INDEX); \
if (process_res_telephone__ != NORMAL) \
    return process_res_telephone__;

#define EXE_GIT(STRING_GIT_COMMAND)  \
    return after(STRING_GIT_COMMAND);

typedef std::map<std::string, std::string> args_table_type;

extern int exec_exit_code_;

std::string exec(const char *cmd, int &exit_code = exec_exit_code_);

std::string exec(std::string const &cmd, int &exit_code = exec_exit_code_);

bool in_git_repos();

class arg {
public:
    std::string name;
    std::string value;
    const char *void_value;
    const char *tip;
    bool (*validate)(std::string const &);
    bool edited;

public:
    arg(const char *name, const char *value, const char *void_value, const char *tip, bool (*validate)(std::string const &) = arg::void_validate, bool edited = false)
            :
            name(name), value(value), void_value(void_value), tip(tip), validate(validate), edited(edited){}

    static bool void_validate(std::string const &value);
    static bool optimistic_validate(std::string const &value);
    static bool bool_validate(std::string const &value);
    static bool mode_validate(std::string const &value);
};

int before(const args_table_type &args_table, arg *args, int arg_num, int help_index, int strict_mode_index);

int after(std::string const &git_cmd);

#endif //GITME_GITME_TYPE_H

