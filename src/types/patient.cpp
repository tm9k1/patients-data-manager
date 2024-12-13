#include "patient.h"

Patient::Patient() = default;

Patient::Patient(const std::string& name, const Date& dob, const Date& surgery_date, const std::string& surgeon_name, JointName joint_name, OperativeSide operative_side)
    : _name(name), _dob(dob), _surgery_date(surgery_date),
    _surgeon_name(surgeon_name), _joint_name(_joint_name), _operative_side(operative_side) {};

std::string Patient::GetJointName() const
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

std::string Patient::GetOperativeSide() const
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


void Patient::PrettyPrint() const
{
    std::cout << "Name: " << Patient::GetName() << std::endl;
    std::cout << "Date of Birth: " << Patient::GetDob() << std::endl;
    std::cout << "Surgery Date: " << Patient::GetSurgeryDate() << std::endl;
    std::cout << "Surgeon Name: " << Patient::GetSurgeonName() << std::endl;

    std::cout << "Joint Name: " << Patient::GetJointName() << std::endl;
    std::cout << "Operative Side: " << Patient::GetOperativeSide() << std::endl;

}
