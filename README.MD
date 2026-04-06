# Error State Kalman Filter

Finished Implementation in C++ and Python -> /Test_Notes. Still making changes for optimization and class for real sensor instead of interating through csv file. This implementation has 0 heap allocation (No New Keyword) as STM 32 does not allow an dynamically allocated sizes thus all types instead of Eigen::VectorXd or Eigen::MatrixXd, all type will have set template arguments and vectors will always be put into Eigen::Vector3d or Eigen::Matrix<double, dim, 1>. 
<table>
  <tr>
    <td width="50%"><img src="https://github.com/HyunLee8/ErrorStateKalmanFilter/blob/c3cf1b0c57cff196f236105c246aefd366c0b9c2/results/orientation_animation.gif?raw=true" width="100%" /></td>
  </tr>
<tr>
    <td width="50%"><img src="https://github.com/HyunLee8/Error-State-Kalman-Filter/blob/main/results/Screenshot%202026-01-02%20at%202.56.02%E2%80%AFPM.png?raw=true" width="100%" /></td>
  </tr>
</table>

## Overview

This ESKF implementation uses quaternion representation for orientation estimation, avoiding gimbal lock issues associated with Euler angles. The filter predicts state using gyroscope and accelerometer data, then corrects the estimates using GPS data. Intuitive explanation is in filter.py comments.

**One important caveat for gravity is that typically in most papers you will see that
gravity is included in the error states however when computing it almost never affects
the kalman gain or any other values when applied. Also it only adds unecessary complexity
thus is not inluded in delta X.

**State Vector (16 elements):**
- Position (3D): `[x, y, z]`
- Orientation (quaternion): `[qw, qx, qy, qz]`
- Velocity (3D): `[vx, vy, vz]`
- Accelerometer bias: `[bax, bay, baz]`
- Gyroscope bias: `[bwx, bwy, bwz]`

**Error State (15 elements):**
- Position error (3D)
- Orientation error (3D rotation vector)
- Velocity error (3D)
- Accelerometer bias error (3D)
- Gyroscope bias error (3D)

## Theoretical Background

This project could not have been done without these resources (The first link is really good on probabalistic intuition). The second link is for implementation. Also check out chapter 6 for implementing update step.

1. **Basic Kalman Filter Intuition**: [How a Kalman Filter Works (in Pictures)](https://www.bzarg.com/p/how-a-kalman-filter-works-in-pictures/)
2. **ESKF with Quaternions** (Sections 5.1-5.4.3): [Quaternion kinematics for the error-state Kalman filter](https://arxiv.org/pdf/1711.02508)
3. **ESKF Generalized Formulas**: [IEEE Paper on ESKF](https://ieeexplore.ieee.org/document/9206131)
4. **Quaternion Intuition**: [Visualizing Quaternions](https://www.youtube.com/watch?v=d4EgbgTm0Bg)
5. **Jacobian Matrix Intuition**: [Jacobian Matrix Explained](https://www.youtube.com/watch?v=6FesMicc844)
6. **Extended Kalman Filter Visualization**: [Extended Kalman Filter Visualized](https://www.youtube.com/watch?v=9X3jGGnbcvU&t=55s)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/hyunlee8/ErrorStateKalmanFilter.git
cd ErrorStateKalmanFilter
```

2. Install required dependencies:
```bash
pip install numpy pandas pyquaternion

### Running the Filter

1. Prepare your sensor data files in the `src/` directory:
   - `IMU_data.csv` - IMU sensor measurements
   - `motion_data.csv` - Position/velocity measurements (optional for updates)

2. Run the filter:
```bash
cd src
python main.py
```