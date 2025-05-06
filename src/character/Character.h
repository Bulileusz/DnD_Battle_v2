#pragma once
#include <string>

class Character {
protected:
    std::string name_;
    int hp_;
    int attack_;
    int defense_;

public:
    Character(std::string name, int hp, int attack, int defense);

    bool isAlive()  const        { return hp_ > 0; }
    int  hp()       const        { return hp_;     }

    int  basicAttack() const;          // zwraca obrażenia
    void takeDamage(int dmg);          // odejmuje HP

    //gettery do walki
    const std::string& name()   const {return name_;    }
    int getAttack()             const {return attack_;  }
    virtual int getDefense()    const {return defense_; }
};
