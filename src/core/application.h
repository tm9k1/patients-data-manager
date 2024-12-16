#pragma once

#include "types/patient.h"

#include <string>
#include <vector>

namespace Application {

static std::vector<Types::Patient_C> _patients_data;

enum ReturnCode {
    OK,
    JSON_BROKEN,
    UNKNOWN
};

class Application_C
{

public:

    ReturnCode exec();

private: //helpers

    void initialize();
    void show();
    void getInput();
    bool startOperation();

private:

    unsigned char _return_code = 0;
    unsigned char _input_code = 0;
};
} // namespace Application