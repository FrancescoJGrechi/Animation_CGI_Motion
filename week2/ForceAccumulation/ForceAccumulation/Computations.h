#pragma once
#ifndef _COMPUTATIONS_
#define _COMPUTATIONS_
#include "pch.h"

void accumulateForces(Eigen::Vector2f f[], Eigen::Vector2f conf[], int index_i, int index_j, float l_0, float spring_k);

void zero_forces(Eigen::Vector2f f[], int num_masses);

#endif // !_COMPUTATIONS_
