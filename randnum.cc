#include <random>
#include <chrono>

static unsigned int randnum() {
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng{seed};

    vector<int> v{};

    for (int i = 0; i < 10000; i++) {
        v.emplace_back(i);
    }
    shuffle(v.begin(), v.end(), rng);
    return v[0];
}
