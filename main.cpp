#include "iostream"
#include "Histogram.h"
#include "RandomEintegerGenerator.h"

int main() {
    std::unique_ptr<Logger> logger = std::make_unique<Logger>();
    Hist::Histogram histogram(std::move(logger));

    // Create RandomEintegerGenerator object
    Hist::RandomEintegerGenerator randomGenerator;

    // Create random data for histogram
    for (int i = 0; i < 100; ++i) {
        Hist::EInteger randomValue = static_cast<Hist::EInteger>(randomGenerator());
        histogram.add(randomValue);
    }

    // Test the functions of the Histogram class
    Hist::EInteger mode = histogram.getMode();
    Hist::EInteger minValue = histogram.getMinValue();
    Hist::EInteger maxValue = histogram.getMaxValue();

    // Print the results
    std::cout << "Mode: " << mode << std::endl;
    std::cout << "Min Value: " << minValue << std::endl;
    std::cout << "Max Value: " << maxValue << std::endl;

    return 0;
}