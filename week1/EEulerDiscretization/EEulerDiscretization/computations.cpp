#include "pch.h"
#include <iostream>

using Eigen::MatrixXf;

// define types
typedef Vector2f (*force_function)(Vector2f& conf, Vector2f& p, float delta_t, MatrixXf& mass);

void euler_discretization(Vector2f& conf, Vector2f& p, MatrixXf mass_mat, float delta_t, force_function f, int number_steps) {

	for (int step = 0; step < number_steps; step++) {
		
		// for non-first step, we call utility functions to update configuration & momentum
		if (step != 0) {
			update_configuration(conf, p, mass_mat, delta_t);
			update_momentum(f, conf, p, mass_mat, delta_t);
		}

		// simple console logging to see effect of iteration
		std::cout << "\n***** START STEP #" << step << " *****" << std::endl;
		std::cout << "Configuration vector: \n" << conf << std::endl;
		std::cout << "Momentum vector: \n" << p << std::endl;
		std::cout << "Mass matrix: \n" << mass_mat << std::endl;
		std::cout << "***** END STEP #" << step << " *****\n" << std::endl;
	}
	


}

// update configuration vector
void update_configuration(Vector2f &conf, Vector2f &p, MatrixXf &mass_mat, float delta_t) {
	conf = ((mass_mat.inverse()) * p)*delta_t + conf;
}

// update momentum vector
void update_momentum(force_function f, Vector2f &conf, Vector2f &p, MatrixXf &mass_mat, float delta_t) {
	p = (f(conf, p, delta_t, mass_mat) * delta_t) + p;
}

