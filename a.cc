#include "potion.h"
#include "ba.h"

using namespace std;

#include <iostream>
#include <memory>

int main () {
    Potion *p = new BA{};
    if (p->getType() == Potion::BA) cout << "yes" << endl;
}