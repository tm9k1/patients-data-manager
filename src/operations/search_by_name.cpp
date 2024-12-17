#include "operations.h"

#include "core/application.h"
#include "types/patient.h"

#include <vector>

namespace {

std::vector<Types::Patient_C> SearchByNameInternal(const std::string& search_string)
{
    const auto& all_patients = Application::Application_C::GetPatientsData();
    std::vector<Types::Patient_C> filtered_patients;
    for (const auto& patient : all_patients) {
        if (patient.GetName().find(search_string) != std::string::npos) {   // we have a match
            filtered_patients.emplace_back(patient);
        }
        // // can be extended to search for other details
        // if (patient.GetSurgeonName().find(search_string) != std::string::npos) {   // we have a match
        //     filtered_patients.emplace_back(patient);
        // }
    }
    return filtered_patients;
}

} // namespace

namespace Operations {

bool SearchByName()
{
    std::string search_string;
    std::cin.ignore(); // get rid of any lingering line breaks
    std::cout << "Please provide Name of the patient." << std::endl;
    std::getline(std::cin, search_string);

    auto matching_elements = SearchByNameInternal(search_string);

    std::cout << "Got it! Searching for \"" << search_string << "\".." << std::endl;

    DisplayPatientDetails(matching_elements);

    return true;
}

} // namespace Operations
