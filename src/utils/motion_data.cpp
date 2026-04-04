/*
Author: Isaac Lee
Date: Jan 10, 2026
Description:
    Here the implementation is the same structure as Sensor_data. 
    Only difference is getting the Position and Velocity from
    the gps. Also no returning a double value.
*/

#include "eskf/utils/motion_data.h"

MotionData::MotionData(const std::vector<std::vector<double>>& data)
    : motionData(data) {}

void MotionData::loadMotionData(const size_t i) {
    Pos << motionData[i][POS_X_COL],
           motionData[i][POS_Y_COL],
           motionData[i][POS_Z_COL];
    
    Vel << motionData[i][VEL_X_COL],
           motionData[i][VEL_Y_COL],
           motionData[i][VEL_Z_COL];
}

Eigen::Vector3d MotionData::getPos() {
    return Pos;
}

Eigen::Vector3d MotionData::getVel() {
    return Vel;
}