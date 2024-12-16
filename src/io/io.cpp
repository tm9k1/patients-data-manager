#include "io.h"

#include <nlohmann/json.hpp>

#include "adapters/patient-json-adapter.h"

#include <fstream>
#include <iostream>
#include <filesystem>

using Json = nlohmann::json;

namespace IO {

Json SerializePatientsData(const std::vector<Types::Patient_C>& patients) {
    Json jsonArray = Json::array();
    for (const auto& patient : patients) {
        Json json = patient;
        jsonArray.push_back(json);
    }
    return jsonArray;
}

bool SaveToJSON(const std::vector<Types::Patient_C>& patients_data)
{
    Json json_object;
    json_object["version"] = 0.1;

    // serialize vector of patients here
    auto patients_serialized = SerializePatientsData(patients_data);
    json_object["patients"] = patients_serialized;

    std::ofstream file(_patients_data_file_name);
    file << std::setw(4) << json_object << std::endl; // TODO Handle write-failures

    return true;
}

std::vector<Types::Patient_C> LoadFromJSON()
{
    // check if file exists already.
    const bool data_file_exists = std::filesystem::exists(_patients_data_file_name);

    // if not exists, create new file and continue as normal.
    if ( !data_file_exists ) {
        SaveToJSON({});
    }

    // parse the json file
    std::ifstream file(_patients_data_file_name);
    Json data;
    try {
        data = Json::parse(file);
    } catch (const nlohmann::json::exception& exception) {
        std:: cerr << exception.what() << std::endl;
        throw std::runtime_error("Could not parse the json file. Is it broken?");
    }

    // extract jsonarray of patients data
    std::vector<Types::Patient_C> vec;

    auto& patients_data_json = data["patients"];
    for (const auto& patient_data_json : patients_data_json) {

        // ... and deserialize into Types::Patient_C objects
        auto patient = patient_data_json.template get<Types::Patient_C>();

        // store into vector for sending back to application
        vec.emplace_back(patient);
    }
    return vec;
}

} // namespace IO
