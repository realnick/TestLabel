//
//  PEUtils.cpp
//
#include "programming.h"
USING_NS_ALL;

#include "PEUtils.h"
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <random>
#include <algorithm>
#include <cctype>
#include <locale>
#include <regex>

static void _normalizeJson(picojson::value &v);

picojson::value PEUtils::parseJson(const string& jsonString)
{
    picojson::value v;
    string err = picojson::parse(v, jsonString);
    if (!err.empty()) {
        PE_LOGE("parseJson failed: %s", err.c_str());
    } else {
        _normalizeJson(v);
    }
    return v;
}

void _normalizeJson(picojson::value &v) {
    if (v.is<picojson::array>())
    {
        for (auto& val : v.get<picojson::array>())
        {
            _normalizeJson(val);
        }
    }
    else if (v.is<picojson::object>())
    {
        auto& obj = v.get<picojson::object>();
        for (auto itr = obj.begin(); itr != obj.end(); itr++)
        {
            _normalizeJson(itr->second);
        }
    }
    else if (v.is<bool>())
    {
        v = (v.get<bool>() == true) ? picojson::value("1") : picojson::value("0");
    }
    else if (v.is<double>())
    {
        ostringstream ostr;
        ostr.precision(12);
        ostr << v.get<double>();
        v = picojson::value(ostr.str());
    }
    else if (v.is<picojson::null>())
    {
        v = picojson::value("");
    }
}
