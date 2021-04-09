#ifndef __mdcore__jsonutils_h
#define __mdcore__jsonutils_h

#include "nlohmann/json.h"

namespace mdcore
{
    typedef nlohmann::json json;
    json readJsonFromFile(std::string filename);
    std::vector<std::string> readJsonArray(std::string filename, std::string element);
    bool writeJsonToFile(std::string filename, json json_object);
}

#endif