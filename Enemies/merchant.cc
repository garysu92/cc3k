#include "merchant.h"

using namespace std;

bool Merchant::hostile = false;

Merchant::Merchant(): Enemy{70, 5, 30, 0, 'M'} {}

bool Merchant::isHostile() {
    return hostile;
}

std::string getType() const {
    return "Merchant (M)";
}
