#pragma once

#include <string>

#include "types/date.h"
#include "types/util.h"

/* PATIENT DATA
//
// - Name: String
// - Date of Birth (DOB): Date
// - Surgery Date: Date
// - Surgeon Name: String
// - Joint Name: Enum (Hip, Shoulder, Knee)
// - Operative Side: Enum (Left, Right)
*/

class Patient_C
{

public:
    // ctors
    Patient_C();

    Patient_C(const std::string& name, const Date_C& dob = Date_C(), const Date_C& surgery_date = Date_C(),
                const std::string& surgeon_name = "", JointName joint_name = JointName::UNDEFINED, OperativeSide operative_side = OperativeSide::UNDEFINED);

    // getters
    std::string GetName()           const { return _name; }
    Date_C GetDob()                   const { return _dob; }
    Date_C GetSurgeryDate()           const { return _surgery_date; }
    std::string GetSurgeonName()    const { return _surgeon_name; }
    std::string GetJointName()      const;
    std::string GetOperativeSide()  const;

    // setters
    void SetName(std::string name)                      { _name = name; }
    void SetDob(Date_C dob)                               { _dob = dob; }
    void SetSurgeryDate(Date_C surgery_date)              { _surgery_date = surgery_date; }
    void SetSurgeonName(std::string surgeon_name)       { _surgeon_name = surgeon_name; }
    void SetJointName(std::string joint_name)           { _surgeon_name = joint_name; }
    void SetOperativeSide(std::string operative_side)   { _surgeon_name = operative_side; }

    // util
    void PrettyPrint() const;

private: // data
    std::string _name;
    Date_C _dob;
    Date_C _surgery_date;
    std::string _surgeon_name;
    JointName _joint_name = JointName::UNDEFINED;
    OperativeSide _operative_side = OperativeSide::UNDEFINED;
};

