#include "patient-json-adapter.h"

namespace Patient {

void to_json(Json& json_object, const Patient::Patient_C& patient) {

    json_object = Json{
            {"name",            patient.GetName()},
            {"date-of-birth",   patient.GetDob().ToString()},
            {"date-of-surgery", patient.GetSurgeryDate().ToString()},
            {"name-of-surgeon", patient.GetSurgeonName()},
            {"joint-name",      patient.GetJointName()},
            {"operative-side",  patient.GetOperativeSide()}
        };
}

void from_json(const Json& json_object, Patient::Patient_C& patient) {

    patient.SetName(json_object["name"].template get<std::string>());
    patient.SetDob(json_object["date-of-birth"].template get<std::string>());
    patient.SetSurgeryDate(json_object["date-of-surgery"].template get<std::string>());
    patient.SetSurgeonName(json_object["name-of-surgeon"].template get<std::string>());
    patient.SetJointName(json_object["joint-name"].template get<std::string>());
    patient.SetOperativeSide(json_object["operative-side"].template get<std::string>());
}

} // namespace Patient
