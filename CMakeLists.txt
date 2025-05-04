cmake_minimum_required(VERSION 3.29)
project(DnD_Battle)

set(CMAKE_CXX_STANDARD 20)

# 🧠 Podajemy ścieżkę do SFML PRZED find_package
set(SFML_DIR "S:/SFML-2.6.1/lib/cmake/SFML")

# Dodajemy main.cpp
add_executable(DnD_Battle src/main.cpp)

# Szukamy SFML
find_package(SFML COMPONENTS graphics window system REQUIRED)

# Podłączamy SFML
target_link_libraries(DnD_Battle sfml-graphics sfml-window sfml-system)
