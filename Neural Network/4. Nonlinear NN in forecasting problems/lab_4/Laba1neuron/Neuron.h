#pragma once
#include "ActivationFunction/ActivationFunction.h"
class Neuron
{
public:
	Neuron() { }
	double input = 0;
	double output = 0;
	double propagationError = 0;
	ActivationFunction* function = nullptr;

	void active();
	double derivative();
};

