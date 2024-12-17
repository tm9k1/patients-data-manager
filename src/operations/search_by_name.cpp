#include "operations.h"

#include "core/application.h"
#include "types/patient.h"

#include <vector>

namespace {

enum class SearchParameter {
    PatientName,
    SurgeonName
};

std::vector<Types::Patient_C> GetMatchingElements(const std::string& search_string, SearchParameter search_param)
{
    const auto& all_patients = Application::Application_C::GetPatientsData();
    std::vector<Types::Patient_C> filtered_patients;
    for (const auto& patient : all_patients) {
        if (search_param == SearchParameter::PatientName) {
            if (patient.GetName().find(search_string) != std::string::npos) {   // we have a match
                filtered_patients.emplace_back(patient);
            }
        } else {
            if (patient.GetSurgeonName().find(search_string) != std::string::npos) {   // we have a match
                filtered_patients.emplace_back(patient);
            }
        }
    }
    return filtered_patients;
}

bool SearchByNameInternal(SearchParameter search_param)
{
    std::string search_string;
    std::cin.ignore(); // get rid of any lingering line breaks

    if (search_param == SearchParameter::PatientName) {
        std::cout << "Please provide Name of the patient." << std::endl;
    } else {
        std::cout << "Please provide Name of the surgeon." << std::endl;
    }

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


} // namespace Operations
