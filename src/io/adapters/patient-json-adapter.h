#pragma once

#include <nlohmann/json.hpp>

#include "types/patient.h"

using Json = nlohmann::json;

/*
// adapter for Patient class implicit de/serialization
*/
namespace Patient {

    void to_json(Json& json_object, const Patient::Patient_C& patient);

    void from_json(const Json& json_object, Patient::Patient_C& patient);

} // namespace Patient
