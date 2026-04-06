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

#include <iostream>
#include "eskf/data/data.h"
#include "eskf/filter/filter.h"
#include "config.h"
#include "eskf/utils/Timer.h"

constexpr int rows = 100;
constexpr int starting_index = 0;

int main() {
    Data data(starting_index);
    ESKF& filter = ESKF::getInstance(data);

    Timer timer;
    timer.start();
    while(filter.iteration < rows) {
        if constexpr (isTesting()) {
            filter.testFrame(CURRENT_TEST);
        } else {
            filter.predict();
            filter.update();
            filter.nextSet();
        }
    }
    timer.stop();

    //testing is obviously faster since it's only checking bounds and data not the actual
    //filter. When active it will do all Eigen math. If you run this in CLion, whatever
    //you put in the config.h as the mode it will say unreachable for the false statement
    //since it is constexpr so the code isn't broken.

    if (isTesting()) {
        std::cout << "Testing Compute Time: " << timer.getTimeSeconds() << "Seconds" << '\n';
    } else {
        std::cout << "Compute Time: " << timer.getTimeSeconds() << "Seconds" << '\n';
    }

    return 0;
}
