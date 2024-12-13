#include "patient-json-adapter.h"

nlohmann::json PatientJsonAdapter::to_json(const Patient_C& data) {
    return nlohmann::json(
        {
            {"name",             data.GetName()},
            {"date-of-birth",   data.GetDob().ToString()},
            {"date-of-surgery", data.GetSurgeryDate().ToString()},
            {"name-of-surgeon", data.GetSurgeonName()},
            {"joint-name",      data.GetJointName()},
            {"operative-side",  data.GetOperativeSide()}
        }
    );
}
// CONTINUE HERE
Patient_C& PatientJsonAdapter::from_json(const nlohmann::json& j) {
    Patient_C p;
    // j.at("id").get_to(data.id);
    // j.at("name").get_to(data.name);
    // j.at("value").get_to(data.value);

    return p;
}
