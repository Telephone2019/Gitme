//
// Created by terry on 10/14/20.
//

#ifndef GITME_GITME_TYPE_H
#define GITME_GITME_TYPE_H

typedef std::map<std::string, std::string> args_table_type;

class arg {
public:
    std::string name;
    std::string value;
    const char *tip;

public:
    arg(const char *name, const char *value, const char *tip)
            :
            name(name), value(value), tip(tip){}
};

#endif //GITME_GITME_TYPE_H
