#pragma once

enum class Mode { TESTING, ACTIVE };
enum class TESTING_TYPE { ALL_VALUES, BOUNDS, NAME_CONFLICTIONS };

//VALUES TO CHANGE
//========================================================
constexpr Mode CURRENT_MODE = Mode::TESTING;
constexpr TESTING_TYPE CURRENT_TEST = TESTING_TYPE::BOUNDS;
//=========================================================


constexpr bool isTesting() { return CURRENT_MODE == Mode::TESTING; }