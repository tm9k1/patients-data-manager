#include "operations.h"

#include "core/application.h"

#include <algorithm>

namespace {

enum SortParameter {
    UNDEFINED = 0,
    PatientName,
    DateOfBirth,
    DateOfSurgery,
    SurgeonName,
    JointName,
    OperativeSide
};

std::vector<Types::Patient_C> GetSortedElements(SortParameter sort_param) {
    auto all_patients = Application::Application_C::GetPatientsDataConst();
    std::sort(all_patients.begin(), all_patients.end(), [sort_param](const Types::Patient_C &a, const Types::Patient_C &b){

        switch(sort_param) {
            case SortParameter::PatientName:    { return Operations::Util::toLower(a.GetName()) < Operations::Util::toLower(b.GetName()); }
            case SortParameter::SurgeonName:    { return Operations::Util::toLower(a.GetSurgeonName()) < Operations::Util::toLower(b.GetSurgeonName()); }
            case SortParameter::DateOfBirth:    { return Operations::Util::toLower(a.GetDob().ToString()) < Operations::Util::toLower(b.GetDob().ToString()); }
            case SortParameter::DateOfSurgery:  { return Operations::Util::toLower(a.GetSurgeryDate().ToString()) < Operations::Util::toLower(b.GetSurgeryDate().ToString()); }
            case SortParameter::JointName:      { return Operations::Util::toLower(a.GetJointName()) < Operations::Util::toLower(b.GetJointName()); }
            case SortParameter::OperativeSide:  { return Operations::Util::toLower(a.GetOperativeSide()) < Operations::Util::toLower(b.GetOperativeSide()); }
            default:                            { return Operations::Util::toLower(a.GetName()) < Operations::Util::toLower(b.GetName()); }
        };
    });

    return all_patients;
}

} // namespace

namespace Operations {

bool SortByField()
{
    int sort_param;
    std::cin.ignore(); // get rid of any lingering line breaks

    std::cout << "Provide a field name (eg: 1 - Patient Name, 2 - Date of Birth, 3 - Date of Surgery, 4 - Surgeon Name, 5 - Joint Name, 6 - Operative Side)" << std::endl;
    std::cin >> sort_param;

    std::cout << "Got it! Sorting.. " << std::endl;

    auto sorted_elements = GetSortedElements((SortParameter)sort_param);

    Operations::DisplayPatientDetails(sorted_elements);

    return true;
}

} // namespace Operations