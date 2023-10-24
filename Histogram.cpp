#include "Histogram.h"
#include <algorithm>

/**
 * @warning Potential errors:
 * - No checks for validity of added values. Values must be within EInteger range.
 * - Retrieving statistics from an empty histogram will return "EInteger::Zero".
 */

using namespace Hist;


Histogram::Histogram(std::unique_ptr<Logger> log)
    : HistogramBase(std::move(log)) {
}

void Histogram::add(EInteger e) {
    data.push_back(e); // Add value to data
}

HistogramBase::HistogramBase(std::unique_ptr<Logger> log) : m_log(std::move(log)) {}

HistogramBase::~HistogramBase() {}

EInteger Histogram::getMode() const {

    // If no data
    if (data.empty()) {
        return EInteger::Zero;
    }

    // Find mode frim data
    EInteger mode = EInteger::Zero;
    int most = 0;

    for (size_t i = 0; i < data.size(); i++) {
        const EInteger& e = data[i];

        int count = std::count(data.begin(), data.end(), e);

        if (count > most) {
            most = count;
            mode = e;
        }
    }

    return mode;
}

EInteger Histogram::getMinValue() const {

    // If no data
    if (data.empty()) {
        return EInteger::Zero;
    }

    // Find minimum value
    return *std::min_element(data.begin(), data.end());
}

EInteger Histogram::getMaxValue() const {

    // If no data
    if (data.empty()) {
        return EInteger::Zero;
    }

    // Find maximum value
    return *std::max_element(data.begin(), data.end());
}