#include "AirspaceManager.hpp"
#include "ConflictEngine.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    AirspaceManager navSystem;

    std::cout << "===============================================" << std::endl;
    std::cout << "   NAV CANADA SkyWatch - Surveillance System   " << std::endl;
    std::cout << "===============================================" << std::endl;

    // Data Simulation / Simulation de données
    Aircraft flights[] = {
        {"ACA101", 45.4215, -75.6972, 30000.0},
        {"WJA550", 45.4230, -75.6990, 30200.0}, // Very close / Très proche
        {"AFR042", 45.6000, -75.8000, 35000.0}
    };

    for (const auto& f : flights) {
        navSystem.updateAircraft(f);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Conflict Analysis / Analyse des conflits
    std::cout << "\n[ANALYSIS/ANALYSE] Checking separation standards..." << std::endl;

    auto activeTracks = navSystem.getAllAircraft();

    // Compare aircraft for conflicts / Comparer les avions pour les conflits
    if (activeTracks.size() >= 2) {
        if (ConflictEngine::isConflict(activeTracks[0], activeTracks[1])) {
            std::cout << "\n!!! ALERT / ALERTE !!!" << std::endl;
            std::cout << "EN: Conflict detected between " << activeTracks[0].callsign << " and " << activeTracks[1].callsign << std::endl;
            std::cout << "FR: Conflit detecte entre " << activeTracks[0].callsign << " et " << activeTracks[1].callsign << std::endl;
        }
    }

    std::cout << "\n--- End of Simulation / Fin de la simulation ---" << std::endl;
    return 0;
}