#ifndef AIRSPACE_MANAGER_HPP
#define AIRSPACE_MANAGER_HPP

#include <vector>
#include <mutex>
#include <string>
#include <iostream>

/**
 * @struct Aircraft
 * @brief Represents flight telemetry data / Représente les données télémétriques de vol.
 */
struct Aircraft {
    std::string callsign;
    double lat;
    double lon;
    double alt;
};

/**
 * @class AirspaceManager
 * @brief Manages the state of aircraft in the airspace / Gère l'état des aéronefs dans l'espace aérien.
 */
class AirspaceManager {
private:
    std::vector<Aircraft> activeFlights;
    mutable std::mutex mtx; // Protects data for thread-safety / Protège les données pour le multi-threading.

public:
    AirspaceManager() = default;

    /**
     * @brief Adds or updates aircraft data / Ajoute ou met à jour les données d'un avion.
     */
    void updateAircraft(const Aircraft& ac);

    /**
     * @brief Clears all active tracks / Réinitialise toutes les pistes actives.
     */
    void clearAirspace();

    /**
     * @brief Returns the number of monitored flights / Retourne le nombre de vols suivis.
     */
    size_t getAircraftCount() const;

    /**
     * @brief Returns a copy of all active aircraft for conflict analysis.
     * @return std::vector<Aircraft>
     */
    std::vector<Aircraft> getAllAircraft() const {
        std::lock_guard<std::mutex> lock(mtx);
        return activeFlights;
    }
};

#endif // AIRSPACE_MANAGER_HPP