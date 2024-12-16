#include "patient.h"

namespace Patient {
Patient_C::Patient_C() = default;

Patient_C::Patient_C(const std::string& name, const Date_C& dob, const Date_C& surgery_date, const std::string& surgeon_name, JointName joint_name, OperativeSide operative_side)
    : _name(name), _dob(dob), _surgery_date(surgery_date),
    _surgeon_name(surgeon_name), _joint_name(joint_name), _operative_side(operative_side) {};

std::string Patient_C::GetJointNameToString() const
{
    switch(_joint_name) {
    case(JointName::HIP):
    {
        return "HIP";
        break;
    }
    case(JointName::KNEE):
    {
        return "KNEE";
        break;
    }
    case(JointName::SHOULDER):
    {
        return "SHOULDER";
        break;
    }
    default:
    {
        return "UNDEFINED";
        break;
    }
    };
}

JointName Patient_C::GetJointNameFromString(const std::string& joint_name_string) const
{
    switch(joint_name_string[0]) {
    case('H'):
    {
        return JointName::HIP;
        break;
    }
    case('K'):
    {
        return JointName::KNEE;
        break;
    }
    case('S'):
    {
        return JointName::SHOULDER;
        break;
    }
    default:
    {
        return JointName::UNDEFINED;
        break;
    }
    };
}

std::string Patient_C::GetOperativeSideToString() const
{
    switch(_operative_side) {
    case(OperativeSide::LEFT):
    {
        return "LEFT";
        break;
    }
    case(OperativeSide::RIGHT):
    {
        return "RIGHT";
        break;
    }
    default:
    {
        return "UNDEFINED";
        break;
    }
    };
}

OperativeSide Patient_C::GetOperativeSideFromString(const std::string& operative_side_string) const
{
    switch(operative_side_string[0]) {
    case('L'):
    {
        return OperativeSide::LEFT;
        break;
    }
    case('R'):
    {
        return OperativeSide::RIGHT;
        break;
    }
    default:
    {
        return OperativeSide::UNDEFINED;
        break;
    }
    };
}


void Patient_C::PrettyPrint() const
{
    std::cout << "Name: " << Patient_C::GetName() << std::endl;
    std::cout << "Date of Birth: " << Patient_C::GetDob() << std::endl;
    std::cout << "Surgery Date: " << Patient_C::GetSurgeryDate() << std::endl;
    std::cout << "Surgeon Name: " << Patient_C::GetSurgeonName() << std::endl;

    std::cout << "Joint Name: " << Patient_C::GetJointName() << std::endl;
    std::cout << "Operative Side: " << Patient_C::GetOperativeSide() << std::endl;

}

} // namespace Patient