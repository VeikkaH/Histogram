#include "RandomEintegerGenerator.h"
#include <random>

namespace Hist {
    EInteger RandomEintegerGenerator::operator()() {
        static std::random_device rd;
        static std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(EInteger::Zero, EInteger::Four);
        return static_cast<EInteger>(distribution(generator));
    }
}