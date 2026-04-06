/*
    NOTES 
    LAST PICKUP: 01/06/2025
    CONTINUE: Most helper functions are complete. Continue defining the contrucutor for filter.py and
              fix some of the imports for utils.
*/

#ifndef FILTER_HPP
#define FILTER_HPP

#include "eskf/data/data.h"
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "eskf/utils/dimensions.h"

enum class TESTING_TYPE;

class ESKF {
private:
    static constexpr double sig_a_noise = 0.01;
    static constexpr double sig_a_walk = 0.01;
    static constexpr double sig_w_noise = 0.01;
    static constexpr double sig_w_walk = 0.01;

    Data dataObject;
    static constexpr double gravity = 9.81;

    Eigen::Matrix<double, Dim::NOMINAL_STATE_DIM, 1> X;
    Eigen::Matrix<double, Dim::ERROR_STATE_DIM, 1> delta_X;
    Eigen::Matrix<double, Dim::ERROR_STATE_DIM, Dim::ERROR_STATE_DIM> P;
    Eigen::Matrix<double, Dim::NOISE_DIM, Dim::NOISE_DIM> Qi;
    Eigen::Matrix<double, Dim::GRAVITY_DIM, 1> Gravity;

    Eigen::Matrix<double, Dim::VECTOR_3D_DIM, 1> Gyro;
    Eigen::Matrix<double, Dim::VECTOR_3D_DIM, 1> Acc;
    Eigen::Matrix<double, Dim::VECTOR_3D_DIM, 1> Pos;
    Eigen::Matrix<double, Dim::VECTOR_3D_DIM, 1> Vel;
    double dt;

    Eigen::Matrix<double, Dim::ERROR_STATE_DIM, Dim::ERROR_STATE_DIM> Fx;
    Eigen::Matrix<double, Dim::ERROR_STATE_DIM, Dim::NOISE_DIM> Fi;

    Eigen::Matrix<double, Dim::MEASUREMENT_DIM, 1> Measurement;
    Eigen::Matrix<double, Dim::MEASUREMENT_DIM, 6> RMeasurement;
    Eigen::Matrix<double, Dim::MEASUREMENT_DIM, 1> U;
    Eigen::Matrix<double, Dim::VECTOR_3D_DIM, Dim::VECTOR_3D_DIM> R;

    int measuredSize;

    Eigen::Matrix<double, Dim::MEASUREMENT_DIM, 1> y;
public:
    int iteration;

public:
    static ESKF& getInstance(Data& data);
    //copy
    ESKF(const ESKF&) = delete;
    ESKF operator=(const ESKF&) = delete;
    //move
    ESKF(const ESKF&&) = delete;
    ESKF operator=(const ESKF&&) = delete;

    static Eigen::Matrix<double, Dim::VECTOR_3D_DIM, Dim::VECTOR_3D_DIM> skewSymmetric(Eigen::Matrix<double, Dim::VECTOR_3D_DIM, 1>& v);

    static Eigen::Matrix<double, Dim::QUATERNION_DIM, Dim::VECTOR_3D_DIM> quaternionSkewSymmetric(Eigen::Matrix<double, Dim::QUATERNION_DIM, 1>& v);

    static Eigen::Quaterniond quaternionRotation(Eigen::Vector3d& three_dim_theta);

    static Eigen::Matrix<double, Dim::ERROR_STATE_DIM, Dim::NOISE_DIM> computeNoiseJacobian(double dt, const Eigen::Matrix3d& R);

    static Eigen::Matrix<double, Dim::ERROR_STATE_DIM, Dim::ERROR_STATE_DIM> computeErrorStateJacobian(double& dt, Eigen::Vector3d& a, Eigen::Vector3d& w, Eigen::Matrix3d& R);

    void nextSet();

    void predict();

    void update();

    void testFrame(TESTING_TYPE);
private:
    explicit ESKF(const Data& data);
};

#endif