cmake_minimum_required(VERSION 3.29)
project(DnD_Battle)

set(CMAKE_CXX_STANDARD 20)

# Ścieżka do SFML (przed find_package)
set(SFML_DIR "S:/SFML-2.6.1/lib/cmake/SFML")

# Pliki źródłowe programu
add_executable(DnD_Battle
        src/main.cpp
        src/character/Character.cpp
        src/logic/Dice.cpp
        src/character/Player.cpp
        src/character/Enemy.cpp
        src/logic/BattleManager.cpp
        src/gui/GameWindow.cpp
        src/screens/MainMenuScreen.cpp
        src/screens/ClassSelectionScreen.cpp
        src/screens/GameScreen.cpp
        src/screens/GameOverScreen.cpp
        src/gui/HealthBar.cpp
        src/gui/HealthBar.h
        src/gui/Button.cpp)

# SFML
find_package(SFML COMPONENTS graphics window system REQUIRED)
target_link_libraries(DnD_Battle sfml-graphics sfml-window sfml-system)
