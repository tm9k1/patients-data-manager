#pragma once

#include <algorithm>

namespace Types {

// Joint Name: Enum (Hip, Shoulder, Knee)
// Operative Side: Enum (Left, Right)

enum class JointName {
    UNDEFINED,
    HIP,
    SHOULDER,
    KNEE
};

enum class OperativeSide {
    UNDEFINED,
    LEFT,
    RIGHT
};

} // namespace Types