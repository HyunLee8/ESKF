//
// Created by Isaac Lee on 4/6/26.
//

#ifndef ERRORSTATEKALMANFILTER_DIMENSIONS_H
#define ERRORSTATEKALMANFILTER_DIMENSIONS_H

namespace Dim {
    inline constexpr int NOMINAL_STATE_DIM = 16;
    inline constexpr int ERROR_STATE_DIM = 15;
    inline constexpr int NOISE_DIM = 12;
    inline constexpr int GRAVITY_DIM = 3;
    inline constexpr int VECTOR_3D_DIM = 3;
    inline constexpr int MEASUREMENT_DIM = 6;
    inline constexpr int QUATERNION_DIM = 4;
};

#endif //ERRORSTATEKALMANFILTER_DIMENSIONS_H