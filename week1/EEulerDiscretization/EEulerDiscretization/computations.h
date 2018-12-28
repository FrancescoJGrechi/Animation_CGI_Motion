#pragma once
#ifndef COMPUTATIONS_H
#define COMPUTATIONS_H

using Eigen::Vector2f;
using Eigen::MatrixXf;

// define types
typedef Vector2f (*force_function)(Vector2f& conf, Vector2f& p, float delta_t, MatrixXf& mass);

void euler_discretization (Vector2f& conf, Vector2f& p, MatrixXf mass_mat, float delta_t, force_function f, int number_steps);
void update_configuration(Vector2f &conf, Vector2f &p, MatrixXf &mass_mat, float delta_t);
void update_momentum(force_function f, Vector2f &conf, Vector2f &p, MatrixXf &mass_mat, float delta_t);

#endif
