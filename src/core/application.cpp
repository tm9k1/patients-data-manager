#include "application.h"

#include "core/date.h"
#include "core/patient.h"

#include <vector>

int Application::exec()
{
    std::vector<Patient> patients;
    std::cout << "PRINTING PATIENT DATA NOW..." << std::endl;
    patients.push_back(Patient("lol"));
    patients.push_back(Patient());
    patients.push_back(Patient());
    patients.push_back(Patient());

    for (const Patient& patient: patients) {
        patient.PrettyPrint();
    }
    return _return_code;
}