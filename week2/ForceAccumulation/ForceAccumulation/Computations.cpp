#include "pch.h"
#include <iostream>

void accumulateForces(Eigen::Vector2f f[], Eigen::Vector2f conf[], int index_i, int index_j, float l_0, float spring_k) {

	// compute distance between masses
	float d_ij = (conf[index_i] - conf[index_j]).norm();

	// compute the vector force on mass_i
	Eigen::Vector2f f_i = -(spring_k * (d_ij - l_0) / d_ij)*(conf[index_i] - conf[index_j]);

	// accumulate the forces
	f[index_i] += f_i;
	f[index_j] += -f_i;

}

void zero_forces(Eigen::Vector2f f[], int num_masses) {

	for (int i = 0; i < num_masses; i++) {
		f[i] = Eigen::Vector2f::Zero();
	}

}