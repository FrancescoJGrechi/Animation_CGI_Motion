#pragma once
#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

#include "pch.h"

// define types
typedef Eigen::Vector2f (*force_function)(Eigen::Vector2f& conf, Eigen::Vector2f& p, float delta_t, Eigen::MatrixXf& mass);

// EXPLICIT EULER DISCRETIZATION WRAPPERS

/* EE for explicitly provided force functions */
void euler_discretization (Eigen::Vector2f& conf, Eigen::Vector2f& p, Eigen::MatrixXf mass_mat, float delta_t, force_function f, int number_steps);
/* EE for force array provided */
void euler_discretization(Eigen::Vector2f conf[], Eigen::Vector2f p[], Eigen::MatrixXf mass_mat, float delta_t, Eigen::Vector2f f[], int num_masses);


void update_configuration(Eigen::Vector2f &conf, Eigen::Vector2f &p, Eigen::MatrixXf &mass_mat, float delta_t);

/* update momentum for explicitly provided force functions */
void update_momentum(force_function f, Eigen::Vector2f &conf, Eigen::Vector2f &p, Eigen::MatrixXf &mass_mat, float delta_t);
/* update momentum for force array provided */
void update_momentum(Eigen::Vector2f &f, Eigen::Vector2f &conf, Eigen::Vector2f &p, Eigen::MatrixXf &mass_mat, float delta_t);

#endif
