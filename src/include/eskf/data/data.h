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
    size_t itr;
    explicit Data(int i);
    double getdt();
    Eigen::Vector3d getAcc();
    Eigen::Vector3d getGyro();
    Eigen::Vector3d getPos();
    Eigen::Vector3d getVel();

    SensorData& getSensorInstance() { return sensorData; }
    MotionData& getMotionInstance() { return motionData; }
};