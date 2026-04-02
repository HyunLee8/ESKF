#pragma once

#include <vector>
#include <string>
#include "eskf/utils/sensor_data.h"
#include "eskf/utils/motion_data.h"

class Data {
private:
    std::vector<std::vector<double>> sensor_data_csv;
    std::vector<std::vector<double>> motion_data_csv;
    std::vector<std::vector<double>> readCSV(const std::string &fileName);

    SensorData sensorData;
    MotionData motionData;
public:
    explicit Data(int i);
    double getdt();
    Eigen::Matrix<double, 3, 1> getAcc();
    Eigen::Matrix<double, 3, 1> getGyro();
    Eigen::Matrix<double, 3, 1> getPos();
    Eigen::Matrix<double, 3, 1> getVel();
};