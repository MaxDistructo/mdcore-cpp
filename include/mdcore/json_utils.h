#ifndef __mdcore__jsonutils_h
#define __mdcore__jsonutils_h

#include "../../../lib/json.hpp"

namespace mdcore
{
    nlohmann::json readJsonFromFile(std::string filename);
    std::vector<std::string> readJsonArray(std::string filename, std::string element);
    bool writeJsonToFile(std::string filename, nlohmann::json json_object);
}

#endif