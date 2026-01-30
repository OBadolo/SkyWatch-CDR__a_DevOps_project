#include "AirspaceManager.hpp"
#include <iostream>

/**
 * Updates aircraft position / Met à jour la position de l'aéronef.
 * Demonstrates thread-safety and input validation.
 */
void AirspaceManager::updateAircraft(const Aircraft& ac) {
    // Basic safety check / Vérification de sécurité de base
    if (ac.alt < 0) {
        std::cerr << "[ERROR] Invalid altitude for / Altitude invalide pour : " << ac.callsign << std::endl;
        return;
    }

    // Thread-safe access / Accès sécurisé via mutex
    std::lock_guard<std::mutex> lock(mtx);

    // In a real system, we would update the existing flight by callsign.
    // Dans un vrai système, on mettrait à jour le vol existant selon l'indicatif.
    activeFlights.push_back(ac);

    std::cout << "[RADAR] New contact / Nouveau contact : " << ac.callsign
        << " @ " << ac.alt << " ft." << std::endl;
}

/**
 * Returns the current traffic count / Retourne le nombre actuel de pistes.
 */
size_t AirspaceManager::getAircraftCount() const {
    std::lock_guard<std::mutex> lock(mtx);
    return activeFlights.size();
}

/**
 * System reset / Réinitialisation du système.
 */
void AirspaceManager::clearAirspace() {
    std::lock_guard<std::mutex> lock(mtx);
    activeFlights.clear();
    std::cout << "[SYSTEM] Airspace cleared / Espace aérien réinitialisé." << std::endl;
}