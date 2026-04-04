/*
Author: Isaac Lee
Date: Jan 10, 2026
Description:
    For preprocessing data, I have a local
    readCSV method implemented manually. C++
    does not have a built in read csv like
    python pandas. To prevent jumbled code,
    I implemented two seperate classes for 
    parsing sensor data and motion data. 
    From there you can call the objects' 
    values and return. Data takes a requred
    arg 'i' in order to iterrate through
    the data frame.
*/

#include "eskf/data/data.h"
#include "eskf/utils/motion_data.h"
#include "eskf/utils/sensor_data.h"
#include <fstream>
#include <sstream>

Data::Data(const int i)
    : sensorData(readCSV("../src/data/sensor_data.csv")),
      motionData(readCSV("../src/data/motion_data.csv")),
      itr(i) {

    sensorData.loadSensorData(itr);
    motionData.loadMotionData(itr);
}

double Data::getdt() {
    return sensorData.getdt();
}

Eigen::Vector3d Data::getAcc() {
    return sensorData.getAcc();
}

Eigen::Vector3d Data::getGyro() {
    return sensorData.getGyro();
}

Eigen::Vector3d Data::getPos() {
    return motionData.getPos();
}

Eigen::Vector3d Data::getVel() {
    return motionData.getVel();
}

std::vector<std::vector<double>> Data::readCSV(const std::string &fileName) {
    std::vector<std::vector<double>> data;
    std::ifstream file(fileName);

    std::string line;
    std::getline(file, line); // skip dis header
    while (std::getline(file, line)) {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(std::stod(cell));
        }
        data.push_back(row);
    }

    file.close();
    return data;
}