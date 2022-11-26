#include "ActivationFunction/ActivationFunction.h"

double AFSigmoid::active(double input)
{
	return 1.0 / (1.0 + exp(-beta * input));
}

double AFSigmoid::derivative(double input, double output)
{
	return beta * (1.0 - output) * output;
}

double AFTanh::active(double input)
{
	return tanh(beta * input);
}

double AFTanh::derivative(double input, double output)
{
	return beta * (1.0 - output * output);
}

double AFATan::active(double input)
{
	return atan(input);
}

double AFATan::derivative(double input, double output)
{
	return 1.0 / (input * input + 1.0);
}

double AFReLu::active(double input)
{
	return (input < 0.0) ? 0 : input;
}

double AFReLu::derivative(double input, double output)
{
	return (input < 0.0) ? 0.0 : 1.0;
}

double AFLinear::active(double input)
{
	return input;
}

double AFLinear::derivative(double input, double output)
{
	return 1.0;
}