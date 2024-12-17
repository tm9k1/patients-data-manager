#include "operations.h"

#include "core/application.h"

namespace Operations {

bool DisplayPatientDetails(const std::vector<Types::Patient_C>& patients)
{
    std::cout << "Here are the details for all the patients:" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "-------------------START--OF--LIST----------------------" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    bool firstElement = true;
    for (const auto patient: patients) {
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