#include "pch.h"
#include <iostream>

void print_configuration(Eigen::Vector2f conf[], int conf_length) {

	for (int i = 0; i < conf_length; i++) {
		std::cout << "Mass[" << i << "] is at: (" << conf[i](0) << ", " << conf[i](1) << ")" << std::endl;
	}
}

void print_momentum(Eigen::Vector2f p[], int p_length) {

	for (int i = 0; i < p_length; i++) {
		std::cout << "Mass[" << i << "] has momentum: (" << p[i](0) << ", " << p[i](1) << ")" << std::endl;
	}
}

void print_forces(Eigen::Vector2f f[], int f_length) {

	for (int i = 0; i < f_length; i++) {
		std::cout << "Mass[" << i << "] has force: (" << f[i](0) << ", " << f[i](1) << ")" << std::endl;
	}
}