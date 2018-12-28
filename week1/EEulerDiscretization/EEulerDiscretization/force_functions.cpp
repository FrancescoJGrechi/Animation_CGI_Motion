#include "pch.h"
#include <iostream>

Vector2f constant_force(Vector2f& conf, Vector2f& p, float delta_t, MatrixXf& mass) {

	// construct vector to be returned
	Vector2f toReturn = Vector2f(2.0*delta_t, -2.0*delta_t);
	return (toReturn);
}
