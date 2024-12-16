#pragma once

#include "types/patient.h"

#include <string>
#include <vector>

namespace Application {


enum ReturnCode {
    OK,
    JSON_BROKEN,
    UNKNOWN
};

class Application_C
{

public:

    ReturnCode exec();

public:
    static std::vector<Types::Patient_C>& GetPatientsData() {return _patients_data;}
    static const std::vector<Types::Patient_C>& GetPatientsDataConst() {return _patients_data;}

private: //helpers

    void initialize();
    void show();
    void getInput();
    bool startOperation();

private:

    unsigned char _return_code = 0;
    unsigned char _input_code = 0;
    static std::vector<Types::Patient_C> _patients_data;
};
} // namespace Application