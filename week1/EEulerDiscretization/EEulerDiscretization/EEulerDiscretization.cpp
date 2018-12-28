// EEulerDiscretization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>

// included datastructures
using Eigen::MatrixXf;
using Eigen::Matrix;
using Eigen::DiagonalMatrix;
using Eigen::Vector2f;

// define constants
#define TOTAL_TIME 10
#define NUM_INTERVALS 100
#define DEG_FREEDOM 2
#define STATE_LENGTH (DEG_FREEDOM * 2)

// define types
typedef Vector2f (*force_function)(Vector2f& conf, Vector2f& p, float delta_t, MatrixXf& mass);

int main()
{
    /*
		FUNCTION CALL SETUP
	*/

	// compute number of steps
	float delta_t = (1.0*TOTAL_TIME) / NUM_INTERVALS;
	float state_length = DEG_FREEDOM * 2;

	// dynamically create state matrix
	Vector2f conf(-2.0f, 2.0f);
	Vector2f p(0.1f, -0.2f);
	
	// define the mass matrix
	MatrixXf mass_mat(2, 2);
	mass_mat << 3, 0,
				0, 7;

	force_function f = &(constant_force);

	/*
		CALL FUNCTION
	*/
	euler_discretization(conf, p, mass_mat, delta_t, f, NUM_INTERVALS);

}