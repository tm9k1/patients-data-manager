#include "patient.h"

Patient_C::Patient_C() = default;

Patient_C::Patient_C(const std::string& name, const Date_C& dob, const Date_C& surgery_date, const std::string& surgeon_name, JointName joint_name, OperativeSide operative_side)
    : _name(name), _dob(dob), _surgery_date(surgery_date),
    _surgeon_name(surgeon_name), _joint_name(joint_name), _operative_side(operative_side) {};

std::string Patient_C::GetJointName() const
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

std::string Patient_C::GetOperativeSide() const
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


void Patient_C::PrettyPrint() const
{
    std::cout << "Name: " << Patient_C::GetName() << std::endl;
    std::cout << "Date of Birth: " << Patient_C::GetDob() << std::endl;
    std::cout << "Surgery Date: " << Patient_C::GetSurgeryDate() << std::endl;
    std::cout << "Surgeon Name: " << Patient_C::GetSurgeonName() << std::endl;

    std::cout << "Joint Name: " << Patient_C::GetJointName() << std::endl;
    std::cout << "Operative Side: " << Patient_C::GetOperativeSide() << std::endl;

}
