#include "json_utils.h"
#include "utils.h"
#include <fstream>

nlohmann::json readJsonFromFile(std::string filename)
{
    std::ifstream file;
    openFile("config/config.json", file);
    nlohmann::json f_json = nlohmann::json::parse(file);
    return f_json;
}
std::vector<std::string> readJsonArray(std::string filename, std::string element)
{
    nlohmann::json j = readJsonFromFile(filename);
    return j;
}
bool writeJsonToFile(std::string filename, nlohmann::json json_object)
{
    return false;
}

