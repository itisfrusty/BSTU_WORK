#include "ActivationFunctionSetter.h"

ActivationFunctionSetter::~ActivationFunctionSetter()
{
	if (currentFunction != nullptr)
	{
		delete currentFunction;
		currentFunction = nullptr;
	}
}

void ActivationFunctionSetter::setFunctionByType(NeuralNet& neuralNet, FunctionsType type)
{
	switch (type)
	{
	case ActivationFunctionSetter::Sigmoid:
		setSigmoidFunction(neuralNet);
		break;
	case ActivationFunctionSetter::Tanh:
		setTanhFunction(neuralNet);
		break;
	case ActivationFunctionSetter::ATan:
		setATanFunction(neuralNet);
		break;
	case ActivationFunctionSetter::ReLu:
		setReLuFunction(neuralNet);
		break;
	default:
		break;
	}
}

void ActivationFunctionSetter::setSigmoidFunction(NeuralNet& neuralNet)
{
	ActivationFunction* newFunction = new AFSigmoid();
	//setFunction(newFunction, neuralNet);
}

void ActivationFunctionSetter::setTanhFunction(NeuralNet& neuralNet)
{
	ActivationFunction* newFunction = new AFTanh();
	//setFunction(newFunction, neuralNet);
}

void ActivationFunctionSetter::setATanFunction(NeuralNet& neuralNet)
{
	ActivationFunction* newFunction = new AFATan();
	//setFunction(newFunction, neuralNet);
}

void ActivationFunctionSetter::setReLuFunction(NeuralNet& neuralNet)
{
	ActivationFunction* newFunction = new AFReLu();
	//setFunction(newFunction, neuralNet);
}

/**void ActivationFunctionSetter::setFunction(ActivationFunction* function, NeuralNet& neuralNet)
{
	if (currentFunction != nullptr)
		delete currentFunction;
	currentFunction = function;
	for (std::vector<Neuron>& layer : neuralNet.getLayers())
	{
		for (Neuron& neuron : layer)
		{
			neuron.setActivationFunction(function);
		}
	}
}
*/