#pragma once

#ifndef _FORCE_FUNCTIONS_H_
#define _FORCE_FUNCTIONS_H_

using Eigen::MatrixXf;

// method which applies constant force to objects
Vector2f constant_force(Vector2f& conf, Vector2f& p, float delta_t, MatrixXf& mass);

#endif 