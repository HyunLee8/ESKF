/*
Author: Isaac Lee
Date: Jan 10, 2026
Index:

    /data       - preprocessing entry point for fetching data as Eigen::Matrix and
                  carries all data.

    /filter     - Entire Error State Kalman Filter logic is in here -> Explanations 
                  provided in filter.cpp

    /include    - .h header files for filter, utils, and data

    /utils      - support functions for fetching sensor and motion data as well
                  as running the filter after main entry point

*/

#include "eskf/data/data.h"
#include "eskf/filter/filter.h"
#include "config.h"

constexpr int rows = 100;
constexpr int starting_index = 0;

int main() {
    Data data(starting_index);
    ESKF& filter = ESKF::getInstance(data);

    while(filter.iteration < rows) {
        if (isTesting()) {
            filter.testFrame(CURRENT_TEST);
        } else {
            filter.predict();
            filter.update();
            filter.nextSet();
        }
    }

    return 0;
}
