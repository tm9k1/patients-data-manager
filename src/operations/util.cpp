#include "operations.h"

namespace Operations {
namespace Util {

std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), [](const char c) {
        return std::tolower(c);
    });
    return result;
}

} // namespace Util

} // namespace Operations