#include <iostream>

enum Division {
    ASSASSIN,
    MEDIC,
    MAGE,
    TANK
};

enum Combat {
    UNKNOWN = -1,
    RANGE,
    MELEE,
    BOTH
};

struct Hero {
    char *name;
    Division division;
    Combat combat;
};

void printHero(Hero *hero) {
    std::cout << "Name: " << hero->name << std::endl;
    std::cout << "Division: " << hero->division << std::endl;
    std::cout << "Combat: " << hero->combat << std::endl;
}

int main() {
    Hero *hero = new Hero();
    hero->name = "Test hero";
    hero->division = ASSASSIN;
    hero->combat = MELEE;
    printHero(hero);
    delete hero->name;
    delete hero;
    return 0;
}