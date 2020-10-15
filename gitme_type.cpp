//
// Created by terry on 10/15/20.
//

#include "gitme_type.h"

std::string exec(const char *cmd) {
    char c;
    std::string result;
    FILE *pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (c = fgetc(pipe), c != EOF) {
        result.append(1, c);
    }
    pclose(pipe);
    return std::move(result);
}

std::string exec(std::string const &cmd) {
    char c;
    std::string result;
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (c = fgetc(pipe), c != EOF) {
        result.append(1, c);
    }
    pclose(pipe);
    return std::move(result);
}