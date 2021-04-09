#include "json_utils.h"

json readJsonFromFile(std::string filename)
{
    std::ifstream file = openFile("config/config.json");
    json f_json = json::parse(file);
    return f_json;
}
std::vector<std::string> readJsonArray(std::string filename, std::string element)
{
    json j = readJsonFromFile(filename);
    return j
}
bool writeJsonToFile(std::string filename, json json_object)
{
    
}

