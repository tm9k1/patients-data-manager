#pragma once

#include "types/patient.h"

#include <string>
#include <vector>

namespace IO {

const std::string _patients_data_file_name = "patients_data.json";

/*
// Class to facilitate Input/Output for persistent storage of patient data
*/

class IO_C
{

public:

// save data passed as serialized string
static bool SaveToJSON(const std::vector<Patient::Patient_C>& patients_data);

// load data from file and return as serialized string
static std::vector<Patient::Patient_C> LoadFromJSON();
};

}
