#pragma once

#include <nlohmann/json.hpp>

#include "types/patient.h"

class PatientJsonAdapter {
public:
    static nlohmann::json to_json(const Patient_C& data);
    static Patient_C& from_json(const nlohmann::json& j);
};