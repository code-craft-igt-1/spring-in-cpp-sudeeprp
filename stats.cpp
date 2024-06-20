#include "stats.h"

#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
    Stats stats;

    if (data.empty()) {
        auto nan = std::numeric_limits<float>::quiet_NaN();
        stats.average = nan;
        stats.min = nan;
        stats.max = nan;
    } else {
        stats.average = std::accumulate(data.begin(), data.end(), 0.0f) / data.size();
        stats.min = *std::min_element(data.begin(), data.end());
        stats.max = *std::max_element(data.begin(), data.end());
    }

    return stats;
}
