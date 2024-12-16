#include "operations.h"

#include "core/application.h"

namespace Operations {

bool DisplayPatientDetails()
{
    std::cout << "Here are the details for all the patients:" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------START--OF--LIST----------------------" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    bool firstElement = true;
    for (const auto patient: Application::Application_C::GetPatientsData()) {
        if (firstElement) {
            firstElement = false;
        } else {
            std::cout << std::endl;
            std::cout << "--------------------------------------------------------" << std::endl;
            std::cout << std::endl;
        }
        patient.PrettyPrint();
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "----------------------END--OF--LIST---------------------" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    return true;
}

} // namespace Operations