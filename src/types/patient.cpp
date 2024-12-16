#include "patient.h"

#include <iomanip>

namespace Types {
Patient_C::Patient_C() = default;

Patient_C::Patient_C(const std::string& name, const Date_C& dob, const Date_C& surgery_date, const std::string& surgeon_name, JointName joint_name, OperativeSide operative_side)
    : _name(name), _dob(dob), _surgery_date(surgery_date),
    _surgeon_name(surgeon_name), _joint_name(joint_name), _operative_side(operative_side) {};

std::string Patient_C::GetJointNameToString() const
{
    switch (_joint_name) {
    case JointName::HIP:
    {
        return "HIP";
        break;
    }
    case JointName::KNEE:
    {
        return "KNEE";
        break;
    }
    case JointName::SHOULDER:
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
    switch (std::tolower(joint_name_string[0])) {
    case 'h':
    {
        return JointName::HIP;
        break;
    }
    case 'k':
    {
        return JointName::KNEE;
        break;
    }
    case 's':
    {
        return JointName::SHOULDER;
        break;
    }
    default:
    {
        throw std::runtime_error("Invalid Joint Name provided.");
        break;
    }
    };
}

std::string Patient_C::GetOperativeSideToString() const
{
    switch (_operative_side) {
    case OperativeSide::LEFT:
    {
        return "LEFT";
        break;
    }
    case OperativeSide::RIGHT:
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
    switch (std::tolower(operative_side_string[0])) {
    case 'l':
    {
        return OperativeSide::LEFT;
        break;
    }
    case 'r':
    {
        return OperativeSide::RIGHT;
        break;
    }
    default:
    {
        throw std::runtime_error("Invalid Operative Side provided.");
        break;
    }
    };
}


void Patient_C::PrettyPrint() const
{
    std::cout << "Name:           " << std::setw(40) << Patient_C::GetName() << std::endl;
    std::cout << "Date of Birth:  " << std::setw(40) << Patient_C::GetDob().ToString() << std::endl;
    std::cout << "Surgery Date:   " << std::setw(40) << Patient_C::GetSurgeryDate().ToString() << std::endl;
    std::cout << "Surgeon Name:   " << std::setw(40) << Patient_C::GetSurgeonName() << std::endl;
    std::cout << "Joint Name:     " << std::setw(40) << Patient_C::GetJointName() << std::endl;
    std::cout << "Operative Side: " << std::setw(40) << Patient_C::GetOperativeSide() << std::endl;

}

} // namespace Types