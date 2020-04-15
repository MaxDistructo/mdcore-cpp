#pragma once

#ifndef MDCORE_JSONUTILS_H
#define MDCORE_JSONUTILS_H
#include <nlohmann/json.hpp>
#include<string>
using json = nlohmann::json;

int toStringArray( json json, std::string arr[] );

#endif