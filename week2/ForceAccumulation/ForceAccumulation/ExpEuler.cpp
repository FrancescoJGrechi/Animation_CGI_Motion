#include "pch.h"
#include <iostream>

// define types
typedef Eigen::Vector2f (*force_function)(Eigen::Vector2f& conf, Eigen::Vector2f& p, float delta_t, Eigen::MatrixXf& mass);

// ***** DISCRETIZATION WRAPPERS *****
/* EE for explicitly provided force functions */
void euler_discretization(Eigen::Vector2f& conf, Eigen::Vector2f& p, Eigen::MatrixXf mass_mat, float delta_t, force_function f) {

		// call update functions
		update_configuration(conf, p, mass_mat, delta_t);
		update_momentum(f, conf, p, mass_mat, delta_t);

}

/* EE for force array */
void euler_discretization(Eigen::Vector2f conf[], Eigen::Vector2f p[], Eigen::MatrixXf mass_mat, float delta_t, Eigen::Vector2f f[], int num_masses) {

	for (int i = 0; i < num_masses; i++) {
		update_configuration(conf[i], p[i], mass_mat, delta_t);
		update_momentum(f[i], conf[i], p[i], mass_mat, delta_t);
	}

}



// ***** UPDATE METHODS *****
// update configuration vector
void update_configuration(Eigen::Vector2f &conf, Eigen::Vector2f &p, Eigen::MatrixXf &mass_mat, float delta_t) {
	conf = ((mass_mat.inverse()) * p)*delta_t + conf;
}

// update momentum vector using a force function
void update_momentum(force_function f, Eigen::Vector2f &conf, Eigen::Vector2f &p, Eigen::MatrixXf &mass_mat, float delta_t) {
	p = (f(conf, p, delta_t, mass_mat) * delta_t) + p;
}

// update momentum vector using a force array
void update_momentum(Eigen::Vector2f &f, Eigen::Vector2f &conf, Eigen::Vector2f &p, Eigen::MatrixXf &mass_mat, float delta_t) {
	p = (f * delta_t) + p;
}