#include "operations.h"

#include "core/application.h"
#include "types/patient.h"

#include <vector>

namespace {

enum class SearchParameter {
    PatientName,
    SurgeonName,
    JointName,
    OperativeSide
};

std::vector<Types::Patient_C> GetMatchingElements(const std::string& search_string, SearchParameter search_param)
{
    const auto& all_patients = Application::Application_C::GetPatientsData();
    std::vector<Types::Patient_C> filtered_patients;
    for (const auto& patient : all_patients) {

        switch (search_param) {

        case SearchParameter::PatientName: {
            if (patient.GetName().find(search_string) != std::string::npos) {   // we have a match
                filtered_patients.emplace_back(patient);
            }
            break;
        }

        case SearchParameter::SurgeonName: {
            if (patient.GetSurgeonName().find(search_string) != std::string::npos) {   // we have a match
                filtered_patients.emplace_back(patient);
            }
            break;
        }

        case SearchParameter::JointName: {
            if (std::tolower(patient.GetJointName()[0]) == std::tolower(search_string[0])) {   // we have a match
                filtered_patients.emplace_back(patient);
            }
            break;
        }

        case SearchParameter::OperativeSide: {
            if (std::tolower(patient.GetOperativeSide()[0]) == std::tolower(search_string[0])) {   // we have a match
                filtered_patients.emplace_back(patient);
            }
            break;
        }

        default:
        {
            return {};
        }
        };

    }
    return filtered_patients;
}

bool SearchByNameInternal(SearchParameter search_param)
{
    std::string search_string;
    std::cin.ignore(); // get rid of any lingering line breaks

    switch (search_param) {
    case SearchParameter::PatientName: {
        std::cout << "Please provide Name of the patient." << std::endl;
        break;
    }

    case SearchParameter::SurgeonName: {
        std::cout << "Please provide Name of the surgeon." << std::endl;
        break;
    }

    case SearchParameter::JointName: {
        std::cout << "Please provide Joint Name (eg: Hip / Knee / Shoulder)." << std::endl;
        break;
    }

    case SearchParameter::OperativeSide: {
        std::cout << "Please provide Operative side (eg: Left / Right)." << std::endl;
        break;
    }

    default:
    {
        return false; // unexpected. the module returns false.
    }
    };

    std::getline(std::cin, search_string);

    auto matching_elements = GetMatchingElements(search_string, search_param);

    std::cout << "Got it! Searching for \"" << search_string << "\".." << std::endl;

    Operations::DisplayPatientDetails(matching_elements);

    return true;
}

} // namespace

namespace Operations {

bool SearchByPatientName() {
    return SearchByNameInternal(SearchParameter::PatientName);
}

bool SearchBySurgeonName() {
    return SearchByNameInternal(SearchParameter::SurgeonName);
}

bool SearchByJointName() {
    return SearchByNameInternal(SearchParameter::JointName);
}
bool SearchByOperativeSide() {
    return SearchByNameInternal(SearchParameter::OperativeSide);
}

} // namespace Operations
