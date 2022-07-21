#include "merchant.h"

using namespace std;

bool Merchant::hostile = false;

Merchant::Merchant(): Enemy{70, 5, 30, 0} {}

bool Merchant::isHostile() {
    return hostile;
}
