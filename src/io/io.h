#pragma once

#include "types/patient.h"

#include <string>
#include <vector>

namespace IO {

const std::string _patients_data_file_name = "patients_data.json";

// Methods to facilitate Input/Output for persistent storage of patient data

// save data to JSON passed as std::vector of patients data
bool SaveToJSON(const std::vector<Types::Patient_C>& patients_data);

// load data from file and return as std::vector of Patients
std::vector<Types::Patient_C> LoadFromJSON();


}
