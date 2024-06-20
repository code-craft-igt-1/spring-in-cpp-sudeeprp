#include "stats.h"

#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
    Stats stats;

    if (data.empty()) {
        stats.average = 0.0f;
        stats.min = 0.0f;
        stats.max = 0.0f;
    } else {
        stats.average = std::accumulate(data.begin(), data.end(), 0.0f) / data.size();
        stats.min = *std::min_element(data.begin(), data.end());
        stats.max = *std::max_element(data.begin(), data.end());
    }

    return stats;
}
