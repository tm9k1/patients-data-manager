#pragma once

#include "types/patient.h"

#include <vector>

namespace Operations {

    bool AddNewPatient();
    bool DisplayPatientDetails(const std::vector<Types::Patient_C>&);
    bool SearchByName();

} // namespace Operations