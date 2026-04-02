/*
Author: Isaac Lee
Date: Jan 10, 2026
Description:
    I wanted the main method to be squeaky
    clean having only one function call so 
    I made a secondary entry point here :O.
*/

#include "eskf/utils/RunFilter.h"
#include "eskf/data/Data.h"
#include "eskf/filter/filter.h"

void RunFilter() {
    Data data(0);
    ESKF TrueFilter(data);
    while(TrueFilter.iterration < 5000) {
        TrueFilter.predict();
        TrueFilter.update();
    }
}

