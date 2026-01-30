# SkyWatch-CD&R : Advanced Flight Surveillance System

## ✈️ Overview / Aperçu
**English:** This C++17 system simulates an Air Traffic Control (ATC) conflict detection engine. It monitors aircraft separation in 3D space and provides automated safety alerts.
**Français :** Ce système en C++17 simule un moteur de détection de conflits pour le contrôle aérien (ATC). Il surveille la séparation des aéronefs dans l'espace 3D et génère des alertes de sécurité automatisées.

## 🛠 Features / Fonctionnalités
- **3D Proximity Calculation:** Uses the Haversine formula for lateral distance and delta-altitude for vertical separation.
- **Calcul de proximité 3D :** Utilise la formule de Haversine pour la distance latérale et le delta-altitude pour la séparation verticale.
- **Multithreaded Processing:** Safe concurrent data access using `std::mutex`.
- **Traitement Multithread :** Accès sécurisé aux données concurrentes via `std::mutex`.
- **Bilingual Alerts:** Real-time logging available in both English and French.
- **Alertes Bilingues :** Journaux en temps réel disponibles en anglais et en français.

## 🏗 Requirements / Prérequis
- **OS:** Windows 10/11 (Visual Studio 2022).
- **Compiler:** MSVC with CMake 3.15+.
- **Language:** C++17.

## 🚀 Installation
```bash
mkdir build && cd build
cmake ..
cmake --build .