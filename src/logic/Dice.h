#pragma once

enum class RollResultType {
    Miss,
    Normal,
    Critical
};

struct RollResult {
    int value;
    RollResultType type;
};

RollResult rollD20();
