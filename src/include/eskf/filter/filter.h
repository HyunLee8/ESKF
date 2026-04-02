/*
    NOTES 
    LAST PICKUP: 01/06/2025
    CONTINUE: Most helper functions are complete. Continue defining the contrucutor for filter.py and
              fix some of the imports for utils.
*/

#ifndef FILTER_HPP
#define FILTER_HPP

#include "eskf/data/data.h"
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <Eigen/Geometry>

class ESKF {
private:
    double sig_a_noise;
    double sig_a_walk;
    double sig_w_noise;
    double sig_w_walk;

    Data dataObject;
    double gravity;

    Eigen::Matrix<double, 16, 1> X;
    Eigen::Matrix<double, 15, 1> delta_X;
    Eigen::Matrix<double, 15, 15> P;
    Eigen::Matrix<double, 12, 12> Qi;
    Eigen::Matrix<double, 3, 1> Gravity;

    Eigen::Matrix<double, 3, 1> Gyro;
    Eigen::Matrix<double, 3, 1> Acc;
    Eigen::Matrix<double, 3, 1> Pos;
    Eigen::Matrix<double, 3, 1> Vel;
    double dt;

    Eigen::Matrix<double, 15, 15> Fx;
    Eigen::Matrix<double, 15, 12> Fi;

    Eigen::Matrix<double, 6, 1> Measurement;
    Eigen::Matrix<double, 6, 6> RMeasurement;
    Eigen::Matrix<double, 6, 1> U;
    Eigen::Matrix<double, 3, 3> R;

    int measuredSize;

    Eigen::Matrix<double, 6, 1> y;
public:
    int iterration;

public:
    ESKF(Data& data);

    Eigen::Matrix<double, 3, 3> skewSymmetric(Eigen::Matrix<double, 3, 1>& v);

    Eigen::Matrix<double, 4, 3> quaternionSkewSymmetric(Eigen::Matrix<double, 4, 1>& v);

    Eigen::Quaterniond quaternionRotation(Eigen::Vector3d& three_dim_theta);

    Eigen::Matrix<double, 15, 12> computeNoiseJacobian(double dt, const Eigen::Matrix3d& R);

    Eigen::Matrix<double, 15, 15> computeErrorStateJacobian(double& dt, Eigen::Vector3d& a, Eigen::Vector3d& w, Eigen::Matrix3d& R);

    void predict();

    void update();
};

#endif