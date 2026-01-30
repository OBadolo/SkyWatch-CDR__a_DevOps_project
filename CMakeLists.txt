cmake_minimum_required(VERSION 3.15)
project(SkyWatch-CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Indique le dossier des en-têtes
include_directories(include)

# On liste uniquement les fichiers .cpp pour l'exécutable
# Les .hpp sont trouvés via include_directories
add_executable(SkyWatch-CPP 
    src/main.cpp 
    src/AirspaceManager.cpp
)

# Messages de statut
message(STATUS "EN: SkyWatch-CPP configuration complete.")
message(STATUS "FR: Configuration de SkyWatch-CPP terminée.")