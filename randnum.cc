#include <algorithm>
#include <random>
#include <chrono>

unsigned int randNum() {
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};

    std::vector<int> v{};

    for (int i = 0; i < 10000; i++) {
        v.emplace_back(i);
    }
    std::shuffle(v.begin(), v.end(), rng);
    return v[0];
}
