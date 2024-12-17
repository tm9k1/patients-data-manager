#pragma once

#include "types/patient.h"

#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

namespace Operations {

namespace Util {
    std::string toLower(const std::string&);
} // namespace Util

    bool AddNewPatient();
    bool DisplayPatientDetails(const std::vector<Types::Patient_C>&);
    bool SearchByPatientName();
    bool SearchBySurgeonName();
    bool SearchByJointName();
    bool SearchByOperativeSide();
    bool SortByField();

} // namespace Operations

