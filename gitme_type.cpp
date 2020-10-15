//
// Created by terry on 10/15/20.
//

#include "gitme_type.h"

std::string exec(const char *cmd, int &exit_code) {
    char c;
    std::string result;
    FILE *pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (c = fgetc(pipe), c != EOF) {
        result.append(1, c);
    }
    exit_code = pclose(pipe);
    return std::move(result);
}

std::string exec(std::string const &cmd, int &exit_code) {
    char c;
    std::string result;
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (c = fgetc(pipe), c != EOF) {
        result.append(1, c);
    }
    exit_code = pclose(pipe);
    return std::move(result);
}

bool arg::void_validate(std::string const &value){
    return !value.empty();
}
bool arg::optimistic_validate(std::string const &value){
    return true;
}

int exec_exit_code_ = 0;