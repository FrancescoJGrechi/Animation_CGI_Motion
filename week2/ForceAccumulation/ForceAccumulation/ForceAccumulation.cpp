#include "pch.h"
#include <iostream>
#include <fstream>
#include <ctime>

// define global constants
#define TOTAL_TIME 2
#define NUMBER_STEPS 20000
#define MASSES 2
#define SPRING_K 500
#define L_0 4.0f
#define LOG_TO_FILE true // writes predicted values to .csv files if set to true
#define LOG_TO_SCREEN false // logs values to screen if set to true

// define global variables
Eigen::Matrix2f mass_mat;
Eigen::Vector2f conf[MASSES]; // mass configurations
Eigen::Vector2f p[MASSES]; // mass momentums
Eigen::Vector2f f[MASSES]; // mass forces


int main()
{
	/*
	LOGGING SET UP
	*/
	// open up file to write to CSV
	std::ofstream firstMass;
	std::ofstream secondMass;
	std::ofstream firstForce;

	if (LOG_TO_FILE) {

		firstMass.open("m1_conf.csv");
		secondMass.open("m2_conf.csv");
		firstForce.open("m1_force.csv");
	}

	if (LOG_TO_SCREEN) {
		// print out global constants
		std::cout << "***** SET UP *****" << std::endl;
		std::cout << "Rest length: " << L_0 << std::endl;
		std::cout << "Spring constant: " << SPRING_K << std::endl;
	}
	

	/*
	INITIALIZATION OF VALUES/SIMULATION SET UP
	*/

	// compute derived constants
	float delta_t = (1.0f * TOTAL_TIME) / NUMBER_STEPS;

	// initialize mass matrix
	mass_mat << 5.0f, 0,
				0, 5.0f;

	// initialize configuration array
	conf[0] = Eigen::Vector2f(-2.25f, 0.0f);
	conf[1] = Eigen::Vector2f(+2.25f, 0.0f);

	// initialize momentum array
	float v_1x = 0.0f;
	float v_1y = 0.0f;
	float v_2x = 0.0f;
	float v_2y = 0.0f;

	p[0] = Eigen::Vector2f(v_1x * mass_mat(0, 0), v_1y * mass_mat(0, 0));
	p[1] = Eigen::Vector2f(v_2x * mass_mat(1, 1), v_2y * mass_mat(1, 1));


	/*
	SIMULATION RUN
	*/

	// start time logging
	std::clock_t start;
	double duration;
	start = std::clock();

	// start iterating over time
	for (int t = 0; t < NUMBER_STEPS; t++) {

		// update all forces at time = t
		for (int i = 0; i < MASSES - 1; i++) {
			for (int j = i + 1; j < MASSES; j++) {
				accumulateForces(f, conf, i, j, L_0, SPRING_K);
			}
		}

		// update all masses simultaneously
		euler_discretization(conf, p, mass_mat, delta_t, f, MASSES);
		
		if (LOG_TO_SCREEN) {
			// log state
			std::cout << "\n***** TIME STEP: " << t << " *****" << std::endl;
			print_configuration(conf, MASSES);
			print_momentum(p, MASSES);
			print_forces(f, MASSES);
		}

		// write to file
		if (LOG_TO_FILE) {
			firstMass << t << "," << conf[0](0) << "," << conf[0](1) << "\n";
			secondMass << t << "," << conf[1](0) << "," << conf[1](1) << "\n";
			firstForce << t << "," << f[1](0) << "," << f[1](1) << "\n";
		}

		// reset the forces to zero
		zero_forces(f, MASSES);

	}// end of time loop


	/*
	WRAP UP
	*/

	// end time logging
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "\n\nDuration:" << duration << "s \n";

	if (LOG_TO_FILE) {
		firstMass.close();
		secondMass.close();
		firstForce.close();
	}

}

