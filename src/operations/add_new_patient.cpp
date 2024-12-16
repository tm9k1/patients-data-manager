#include "operations.h"

#include "core/application.h"
#include "io/io.h"

#include <iostream>
#include <string>
#include <cctype>

namespace Operations {
bool GetDetails(Types::Patient_C& patient);

bool AddNewPatient()
{

    while (true) {
        Types::Patient_C patient;

        if (!GetDetails(patient)) {
            continue;
        }

        std::cout << "Got it! Please review the details provided:\n";
        patient.PrettyPrint();

        std::string confirmation_string;

        std::cout << "To confirm, type in \"Confirm\". To discard, type \"Discard\". Press Enter key when you're done typing." << std::endl;
        std::cin >> confirmation_string;
        if (std::tolower(confirmation_string[0]) == 'c') {
            Application::Application_C::GetPatientsData().emplace_back(patient);
            IO::SaveToJSON(Application::Application_C::GetPatientsData());
            std::cout << "Saved to memory!\n";
        } else {
            std::cout << "Discarded from memory!\n";
        }

        std::cout << "If you'd like to return to the main menu, type in \"Exit\". To add another patient,  type \"Add\". Press Enter key when you're done typing." << std::endl;
        std::cin >> confirmation_string;
        if (std::tolower(confirmation_string[0]) == 'e') {
            break;
        }
    }
    return true;
}

bool GetDetails(Types::Patient_C& patient)
{

    try {
        std::string temp;
        std::cin.ignore(); // get rid of any lingering line breaks

        std::cout << "Please provide full name of the patient." << std::endl;
        std::getline(std::cin, temp);
        patient.SetName(temp);
        temp.clear();

        std::cout << "Please provide Date of Birth of the patient in DD/MM/YYYY format" << std::endl;
        std::getline(std::cin, temp);
        patient.SetDob(temp);
        temp.clear();

        std::cout << "Please provide Date of Surgery of the patient in DD/MM/YYYY format" << std::endl;
        std::getline(std::cin, temp);
        patient.SetSurgeryDate(temp);
        temp.clear();

        std::cout << "Please provide Name of Surgeon of the patient \"" << patient.GetName() << "\"" << std::endl;
        std::getline(std::cin, temp);
        patient.SetSurgeonName(temp);
        temp.clear();

        std::cout << "Please provide Surgery Joint Name (eg: Hip / Knee / Shoulder)" << std::endl;
        std::getline(std::cin, temp);
        patient.SetJointName(temp);
        temp.clear();

        std::cout << "Please provide Operative Side for the planned \"" << patient.GetJointName() <<" SURGERY\" (eg: Left / Right) "<< std::endl;
        std::getline(std::cin, temp);
        patient.SetOperativeSide(temp);

    } catch (std::runtime_error exception) {
        std::cerr << exception.what();
        std::cout << "The form is being reset. To fill the form again, press Enter key.\n";
        return false;
    }

    return true;

}

} // namespace Operations