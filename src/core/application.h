#pragma once

#include "types/patient.h"

#include <string>
#include <vector>

class Application_C
{

public:

    int exec();
    void show();

private:

    unsigned char _return_code = 0;
    std::vector<Patient_C> _patients_data;

};