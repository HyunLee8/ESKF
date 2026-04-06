#ifndef MOTION_DATA_H
#define MOTION_DATA_H

#include <Eigen/Dense>
#include <vector>
#include "eskf/utils/dimensions.h"

class MotionData {
private:
    std::vector<std::vector<double>> motionData;
    Eigen::Matrix<double, Dim::VECTOR_3D_DIM, 1> Pos;
    Eigen::Matrix<double, Dim::VECTOR_3D_DIM, 1> Vel;

    static constexpr int POS_X_COL = 0;
    static constexpr int POS_Y_COL = 1;
    static constexpr int POS_Z_COL = 2;
    static constexpr int VEL_X_COL = 3;
    static constexpr int VEL_Y_COL = 4;
    static constexpr int VEL_Z_COL = 5;

public:
    explicit MotionData(const std::vector<std::vector<double>>& data);

    void loadMotionData(size_t i);

    Eigen::Vector3d getPos();

    Eigen::Vector3d getVel();
};

#endif