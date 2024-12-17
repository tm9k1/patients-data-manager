#include "application.h"

#include "io/io.h"
#include "operations/operations.h"

namespace Application {

std::vector<Types::Patient_C> Application_C::_patients_data;

bool isValid(const u_char input)
{
    if (input > 8) {
        return false;
    }
    return true;
}

ReturnCode Application_C::exec()
{
    try {
        Application_C::initialize();
    } catch (std::runtime_error exception) {
        std::cerr << exception.what() << std::endl;
        return ReturnCode::JSON_BROKEN;
    }

    while (true) {
        Application_C::show();
        Application_C::getInput();
        if (isValid(_input_code)) {
            if (_input_code == 0) { break; }
            auto success = Application_C::startOperation();
            if (!success) {
                std::cerr << "Something went wrong. Try again?\n";
            } else {
                std::cout << "Returning to the main menu.\n";
            }
        } else {
            std::cout << "Invalid Input ! Try again.\n";
        }
    }

    return ReturnCode::OK;
}


void Application_C::show()
{
    std::cout << "List of Operations:\n";
    std::cout << "1. Add a new patient\n";
    std::cout << "2. Display patient details\n";
    std::cout << "3. Search by name\n";
    std::cout << "4. Search by surgeon name\n";
    std::cout << "5. Search by joint name\n";
    std::cout << "6. Search by operative side\n";
    std::cout << "7. Sort by any field\n";
    std::cout << "8. Filter by any field\n";
    std::cout << "0. Exit\n";
}

void Application_C::initialize()
{
    // if exists, initialize data from the file
    std::cout << "Initializing Patient data.." << std::endl;
    _patients_data = IO::LoadFromJSON();
}

void Application_C::getInput()
{
    std::cin >> _input_code;
    _input_code -= 48; // correction from char '0' to int 0
}

bool Application_C::startOperation()
{
    switch(_input_code) {
        case 1: {
            return Operations::AddNewPatient();
        }
        case 2: {
            return Operations::DisplayPatientDetails(_patients_data);
        }
        case 3: {
            return Operations::SearchByName();
        }
        default: {
            return false;
        }
    }
}

} // namespace Application