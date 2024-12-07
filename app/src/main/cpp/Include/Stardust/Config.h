//
// Created by karma on 11/25/23.
//

#ifndef LSTARDUST_CONFIG_H
#define LSTARDUST_CONFIG_H

#include <fstream>

#include "json.hpp"
using json = nlohmann::ordered_json;

enum class JsonOperation {
    TO,
    FROM
};

struct Feature {
    char name[33];
    bool enabled;
};

template <typename T>
class ConfigType
{
public:
    void processJson(json& j, JsonOperation operation) {
        Feature* featurePtr = reinterpret_cast<Feature*>(this);
        int numFeatures = sizeof(T) / sizeof(Feature);

        for (int i = 0; i < numFeatures; ++i) {
            if (operation == JsonOperation::TO) {
                j[featurePtr->name] = featurePtr->enabled;
            } else if (operation == JsonOperation::FROM) {
                if (j.contains(featurePtr->name)) {
                    featurePtr->enabled = j[featurePtr->name];
                }
            }
            ++featurePtr;
        }
    }

    void writeToFile(const std::string& filePath) {
        json j;
        this->processJson(j, JsonOperation::TO);
        std::ofstream o(filePath);
        o << j.dump(4);
        o.close();
    }
};



#endif //LSTARDUST_CONFIG_H
