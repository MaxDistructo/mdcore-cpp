#include"jsonutils.h"
#include"constants.h"
#include"nlohmann/json.hpp"
#include"errorLogger.h"
#include<array>
#include<string>

int toStringArray( json json, std::string arr[])
{
    if (!json.is_array()){
        printError( R"(mdcore_jsonutils)", 9, -1,
                    R"(Provided JSON is not an Array)" );
        return -1;
    }

    int i = 0;
    for (auto it = json.array.begin; it != json.array.end; it++){
        arr[i] = it;
        i++;
    }

    return 0;
}