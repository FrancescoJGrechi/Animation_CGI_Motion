#pragma once
#ifndef _UTILITIES_
#define _UTILITIES_
#include "pch.h"

void print_configuration(Eigen::Vector2f conf[], int conf_length);
void print_momentum(Eigen::Vector2f p[], int p_length);
void print_forces(Eigen::Vector2f f[], int f_length);

#endif // !_UTILITIES_
