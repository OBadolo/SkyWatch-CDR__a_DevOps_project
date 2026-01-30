#ifndef CONFLICT_ENGINE_HPP
#define CONFLICT_ENGINE_HPP

#include "AirspaceManager.hpp"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class ConflictEngine {
public:
    // Aviation standards / Normes aéronautiques
    static constexpr double MIN_LATERAL_SEP = 5.0;   // 5 Nautical Miles
    static constexpr double MIN_VERTICAL_SEP = 1000.0; // 1000 Feet

    static bool isConflict(const Aircraft& a, const Aircraft& b) {
        double latDist = calculateDistance(a.lat, a.lon, b.lat, b.lon);
        double altDist = std::abs(a.alt - b.alt);

        return (latDist < MIN_LATERAL_SEP && altDist < MIN_VERTICAL_SEP);
    }

private:
    static double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
        // Haversine formula / Formule de Haversine
        double dLat = (lat2 - lat1) * M_PI / 180.0;
        double dLon = (lon2 - lon1) * M_PI / 180.0;
        double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
            std::cos(lat1 * M_PI / 180.0) * std::cos(lat2 * M_PI / 180.0) *
            std::sin(dLon / 2) * std::sin(dLon / 2);
        return 2 * 3440.06 * std::asin(std::sqrt(a)); // Result in Nautical Miles
    }
};

#endif#pragma once