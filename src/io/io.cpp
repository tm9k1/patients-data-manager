#include "io.h"

#include <nlohmann/json.hpp>

#include "adapters/patient-json-adapter.h"

#include <fstream>
#include <iostream>

using Json = nlohmann::json;

namespace IO {

Json SerializePatientsData(const std::vector<Patient::Patient_C>& patients) {
    Json jsonArray = Json::array();
    for (const auto& patient : patients) {
        Json json = patient;
        jsonArray.push_back(json);
    }
    return jsonArray;
}

bool IO_C::SaveToJSON(const std::vector<Patient::Patient_C>& patients_data)
{
    Json json_object;
    json_object["version"] = 0.1;

    // serialize vector of patients here
    auto patients_serialized = SerializePatientsData(patients_data);
    json_object["patients"] = patients_serialized;

    std::ofstream file(_patients_data_file_name);
    file << std::setw(4) << json_object << std::endl;

    return true;
}

std::vector<Patient::Patient_C> IO_C::LoadFromJSON()
{
    // parse the json file
    std::ifstream file(_patients_data_file_name);
    Json data = Json::parse(file);

    // extract jsonarray of patients data
    std::vector<Patient::Patient_C> vec;

    auto& patients_data_json = data["patients"];
    for (const auto& patient_data_json : patients_data_json) {

        // ... and deserialize into Patient::Patient_C objects
        auto patient = patient_data_json.template get<Patient::Patient_C>();

        // store into vector for sending back to application
        vec.emplace_back(patient);
    }
    return vec;
}

} // namespace IO
