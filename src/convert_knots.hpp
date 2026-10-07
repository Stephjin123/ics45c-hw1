#pragma once

inline double knots_to_miles_per_minute(int knot) {
    return static_cast<double>(knot) * 6076.0 / 5280.0 / 60.0;
}
