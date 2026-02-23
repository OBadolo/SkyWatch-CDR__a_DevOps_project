# ✈️ SkyWatch-CDR
### Automated Conflict Detection & Resolution System
*Système Automatisé de Détection et de Résolution de Conflits*

---

## 📖 Project Overview / Aperçu du Projet

**English:** SkyWatch-CDR is a C++17 flight surveillance simulation designed to monitor airspace integrity. The system ingests real-time aircraft telemetry and evaluates separation standards between active tracks. It identifies potential **Loss of Separation (LoS)** events by calculating 3D distances using professional aviation criteria (**5 NM horizontal / 1000 ft vertical**).

**Français :** SkyWatch-CDR est une simulation de surveillance de vol en C++17 conçue pour surveiller l'intégrité de l'espace aérien. Le système traite la télémétrie des aéronefs en temps réel et évalue les normes de séparation entre les pistes actives. Il identifie les événements potentiels de **perte de séparation (LoS)** en calculant les distances 3D selon les critères aéronautiques professionnels (**5 NM horizontal / 1000 ft vertical**).

---

## 🛠️ Key Technical Features / Caractéristiques Techniques

### 🌐 Geodesic Calculations (Haversine)
**EN:** Implements spherical trigonometry to account for Earth's curvature, ensuring precise lateral distance calculations between GPS coordinates.

**FR:** Implémente la trigonométrie sphérique pour tenir compte de la courbure de la Terre, garantissant des calculs de distance latérale précis.

### 🔒 Thread-Safe Architecture
**EN:** Utilizes `std::mutex` and `std::lock_guard` to manage concurrent access to the airspace data, preventing race conditions in a simulated real-time environment.

**FR:** Utilise `std::mutex` pour gérer l'accès concurrent aux données, évitant les conflits d'accès dans un environnement temps réel simulé.

### 🗣️ Bilingual Logging Engine
**EN:** A fully localized console output system **(EN/FR)** designed for the Canadian Air Traffic Management (ATM) context.

**FR:** Système de journaux (logs) entièrement bilingue **(EN/FR)** conçu pour le contexte de la gestion du trafic aérien (ATM) canadien.

### 🧱 Object-Oriented Design (OOD)
**EN:** Strict separation of concerns between data management (`AirspaceManager`), detection logic (`ConflictEngine`), and the simulation runner.

**FR:** Séparation stricte des responsabilités entre la gestion des données, la logique de détection et le moteur de simulation.

---

## 📊 Separation Standards / Normes de Séparation

> The system triggers a **Conflict Alert** when two aircraft violate the following thresholds.
> *Le système déclenche une **alerte de conflit** lorsque deux aéronefs ne respectent pas les seuils suivants.*

| Parameter | Threshold |
|---|---|
| 📏 Lateral Distance | `< 5.0 Nautical Miles (NM)` |
| 📐 Vertical Separation | `< 1 000 Feet (ft)` |

---

## 🏗️ Directory Structure / Structure des Répertoires

```
SkyWatch-CDR/
├── include/           # Header files (.hpp) / Fichiers d'en-tête
├── src/               # Source files (.cpp) / Fichiers sources
├── CMakeLists.txt     # Build configuration / Configuration de compilation
└── README.md          # Project documentation / Documentation
```

---

## 🚀 Build & Execution / Compilation et Exécution

**Requirements / Prérequis :** CMake 3.15+ and a C++17 compatible compiler (MSVC 2022 recommended).

```bash
# 1. Configure the project / Configurer le projet
cmake -B build

# 2. Build the executable / Compiler l'exécutable
cmake --build build --config Release

# 3. Run / Exécuter
./build/Release/SkyWatch-CPP.exe
```

---

## 📝 About the Developer / À propos du développeur

**EN:** Developed as a demonstration of software engineering skills for safety-critical systems, focusing on performance, concurrency, and internationalization standards.

**FR:** Développé comme une démonstration de compétences en ingénierie logicielle pour les systèmes critiques, avec un accent sur la performance, la concurrence et les normes d'internationalisation.
