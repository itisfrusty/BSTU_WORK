#pragma once

#include <math.h>

class ActivationFunction
{
public:
	virtual ~ActivationFunction() { }
	virtual double active(double input) = 0;
	virtual double derivative(double input, double output) = 0;
};

class AFSigmoid : public ActivationFunction
{
public:
	~AFSigmoid() { }
	inline void setBeta(double value = 1.0) { beta = value; }
	double active(double input) override;
	double derivative(double input, double output) override;
private:
	double beta = 1.0;
};

class AFTanh : public ActivationFunction
{
public:
	~AFTanh() { }
	inline void setBeta(double value = 1.0) { beta = value; }
	double active(double input) override;
	double derivative(double input, double output) override;
private:
	double beta = 1.0;
};

class AFATan : public ActivationFunction
{
public:
	~AFATan() { }
	double active(double input) override;
	double derivative(double input, double output) override;
};

class AFReLu : public ActivationFunction
{
public:
	~AFReLu() { }
	double active(double input) override;
	double derivative(double input, double output) override;
};

class AFLinear : public ActivationFunction
{
public:
	double active(double input) override;
	double derivative(double input, double output) override;
};