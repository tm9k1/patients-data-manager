#include "io.h"

#include <nlohmann/json.hpp>

#include "adapters/patient-json-adapter.h"

#include <fstream>
#include <iostream>

using Json = nlohmann::json;

namespace IO {

Json SerializePatientsData(const std::vector<Patient_C>& patients) {
    nlohmann::json jsonArray = nlohmann::json::array();
    for (const auto& patient : patients) {
        Json json = PatientJsonAdapter::to_json(patient);
        jsonArray.push_back(json);
    }
    return jsonArray;
}

bool IO_C::SaveToJSON(const std::vector<Patient_C>& patients_data)
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

std::vector<Patient_C>& IO_C::LoadFromJSON()
{
    std::ifstream file(_patients_data_file_name);
    // json json_data;
    // file >> json_data;
    // return json_data.dump(4);
    std::vector<Patient_C> vec;
    return vec;
}



}
