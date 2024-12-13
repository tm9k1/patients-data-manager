#include "application.h"

#include "io/io.h"

int Application_C::exec()
{
    // std::vector<Patient> patients;
    // std::cout << "PRINTING PATIENT DATA NOW..." << std::endl;
    // patients.push_back(Patient("lol"));
    // patients.push_back(Patient());
    // patients.push_back(Patient());
    // patients.push_back(Patient());

    // for (const Patient& patient: patients) {
    //     patient.PrettyPrint();
    // }
    // Application_C::show();


    // IO_C::SaveData(R"(
    // {
    //     "name": "John",
    //     "age": 32,
    //     "car": null
    // })", _patient_data_file_name);
    Patient_C patient1("abcd", Date_C("01/01/1999"), Date_C("01/01/2020"), "Arnab Goswami", JointName::HIP, OperativeSide::LEFT);
    Patient_C patient2("xyz", Date_C("01/01/1993"), Date_C("01/01/2000"), "Arnab Gonzales", JointName::HIP,OperativeSide::LEFT);
    Patient_C patient3("lolwa", Date_C("01/01/1996"), Date_C("01/01/2030"), "Arnab Goswami", JointName::HIP, OperativeSide::LEFT);
    _patients_data.push_back(patient1);
    _patients_data.push_back(patient2);
    _patients_data.push_back(patient3);

    IO::IO_C::SaveToJSON(_patients_data);
    return _return_code;
}


void Application_C::show() {
    std::cout << "List of Operations:\n";
    std::cout << "1. Add a new patient\n";
    std::cout << "2. Display patient details\n";
    std::cout << "3. Search by name\n";
    std::cout << "4. Search by surgeon name\n";
    std::cout << "5. Search by joint name\n";
    std::cout << "6. Search by operative side\n";
    std::cout << "7. Sort by any field\n";
    std::cout << "8. Filter by any field\n";
}
