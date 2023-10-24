#pragma once
#include "HistogramBase.h"
#include <random>

namespace Hist {
    class RandomEintegerGenerator : public RandomEintegerGeneratorBase {
    public:
        EInteger operator()() override;
    };
}