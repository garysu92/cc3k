#include <string>
#include "goblin.h"
#include "../Entities/enemy.h"
#include <string>

using namespace std;

Goblin::Goblin(): Enemy{5, 10, 70, 1, 'N'} {}

bool Goblin::isHostile() { 
    return true;
}

<<<<<<< HEAD
std::string Goblin::getType() const {
=======
string Goblin::getType() const {
>>>>>>> d670a007c2f947c7fcc7b76b33f6860fd501b710
    return "Goblin (N)";
}
