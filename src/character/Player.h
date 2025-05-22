#pragma once
#include "Character.h"

class Player : public Character {

public:
    enum class ClassType { Warrior, Mage, Archer };

    explicit Player(ClassType type);

    ClassType getClassType() const;

    void gainExp(int amount);
    void checkLevelUp();

    int getLevel()  const { return level_;  }
    int getExp()    const { return exp_;    }

    int getDefense()    const override {
        return isDefending_ ? defense_ + 5 : defense_;
    }

    void setDefending(bool state)   { isDefending_ = state; }
    bool isDefending()              {return isDefending_;   }

    void reset();

    void heal(int amount);
    int getMaxHp() const;
    int getBaseHp() const;

    std::string getSpritePath() const;
private:
    ClassType classType_;
    int level_;
    int exp_;
    bool isDefending_ = false;
    void initStats();
};


