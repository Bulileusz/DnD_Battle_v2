#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "../screens/Screen.h"


class Screen;

class GameWindow {
public:
    void run();

private:
    std::unique_ptr<Screen> currentScreen;
};
