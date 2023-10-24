#pragma once
#include "HistogramBase.h"
#include <vector>

namespace Hist {

    class Histogram : public HistogramBase {

    public:
        Histogram(std::unique_ptr<Logger> log);
        void add(EInteger e) override;
        EInteger getMode() const override;
        EInteger getMinValue() const override;
        EInteger getMaxValue() const override;

    private:
        std::vector<EInteger> data; // Vector for easier data storage and manipulation
    };
}