#ifndef _mdcore_Config_h
#define _mdcore_Config_h

#include <fstream>
#include "../lib/json.hpp"
#include "json_utils.h"
#include "utils.h"

typedef nlohmann::json json;

namespace mdcore{
    std::string readToken()
    {
        std::ifstream file;
        openFile("config/config.json", file);
        json f_json = json::parse(file);
        std::string token;
        f_json.at("token").get_to(token);
        return token;
    };
    std::string readOwnerId()
    {
        std::ifstream file;
        openFile("config/config.json", file);
        json f_json = json::parse(file);
        std::string token;
        f_json.at("ownerId").get_to(token);
        return token;
    };
    std::string readPrefix()
    {
        std::ifstream file;
        openFile("config/config.json", file);
        json f_json = json::parse(file);
        std::string token;
        f_json.at("prefix").get_to(token);
        return token;
    };
}

#endif