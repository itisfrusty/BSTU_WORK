#include "NeuralNet.h"

Layer::Layer(int count) {
	for (int i = 0; i < count; i++)
		neurons.push_back(Neuron());
}

Layer::Layer(int count, Layer& nextLayer) {
	for (int i = 0; i < count; i++)
		neurons.push_back(Neuron());
	for (int i = 0; i < (count + 1) * nextLayer.neurons.size(); i++)
		weights.push_back(double( rand() % 200 - rand() % 100) / 1000.0);
}

double Layer::getWeight(int i, int j) {
	return weights[i * (weights.size() / neurons.size()) + j];
}

void Layer::setWeight(int i, int j, double value) {
	weights[i * (weights.size() / neurons.size()) + j] = value;
}

double Layer::getThreshold(int j) {
	return weights[neurons.size() + j];
}

void Layer::setThreshold(int j, double value) {
	weights[neurons.size() + j] = value;
}

NeuralNet::NeuralNet(int inputSize, int hiddenCount, int hiddenSize, int outputSize) {
	layers.push_back(Layer(outputSize));
	for (int i = 0; i < hiddenCount; i++)
		layers.insert(layers.begin(), Layer(hiddenSize, *layers.begin()));
	layers.insert(layers.begin(), Layer(inputSize, *layers.begin()));
	for (int i = 0; i < layers.size(); i++)
		std::cout << "L" << i << ": " << layers[i].neurons.size() << "\tW: 0." << layers[i].weights.size() << std::endl;
}

void NeuralNet::setActivationFunction(Layer& layer, std::shared_ptr<ActivationFunction>& function) {
	for (auto& neuron : layer.neurons)
		neuron.function = function.get();
}

void NeuralNet::input(std::vector<double>& inputData) {
	for (int i = 0; i < layers[0].neurons.size(); i++) {
		layers[0].neurons[i].input = inputData[i];
		layers[0].neurons[i].active();
	}
}

void NeuralNet::feedForward() {
	for (int l = 1; l < layers.size(); l++) {
		for (int j = 0; j < layers[l].neurons.size(); j++) {
			double S = 0.0;
			for (int i = 0; i < layers[l-1].neurons.size(); i++) {
				S += layers[l-1].neurons[i].output * layers[l-1].getWeight(i, j);
			}
			S -= layers[l-1].getThreshold(j);
			layers[l].neurons[j].input = S;
			layers[l].neurons[j].active();
		}
	}
}

std::vector<double> NeuralNet::outputVector() {
	std::vector<double> out;
	feedForward();
	for (int i = 0; i < layers[layers.size() - 1].neurons.size(); i++)
		out.push_back(layers[layers.size() - 1].neurons[i].output);
	return out;
}

void NeuralNet::trainNetwork(std::vector<double>& trainData) {
	feedForward();
	int currentLayer = layers.size() - 1;
	int nextLayer = layers.size() - 1;

	alpha = 0.0;
	for (int i = 0; i < layers[0].neurons.size(); i++)
		alpha += layers[0].neurons[i].output * layers[0].neurons[i].output;
	alpha = 1.0 / (1.0 + alpha);

	for (size_t i = 0; i < layers[currentLayer].neurons.size(); i++) {
		layers[currentLayer].neurons[i].propagationError = layers[currentLayer].neurons[i].output - trainData[i];
	}

	for (int nl = layers.size() - 2; nl > 0; nl--) {
		currentLayer = nl;
		nextLayer = nl + (size_t)1;
		for (int i = 0; i < layers[currentLayer].neurons.size(); i++)
		{
			double y = 0.0;
			for (int j = 0; j < layers[nextLayer].neurons.size(); j++)
			{
				y += layers[nextLayer].neurons[j].propagationError * layers[nextLayer].neurons[j].derivative() * layers[currentLayer].getWeight(i, j);
			}
			layers[currentLayer].neurons[i].propagationError = y;
		}
	}

	for (int i = 0; i < layers.size() - 1; i++) {
		for (int k = 0; k < layers[i].neurons.size(); k++)
			for (int j = 0; j < layers[i + (size_t)1].neurons.size(); j++) {
				layers[i].setWeight(k, j, layers[i].getWeight(k, j) - alpha * layers[i + (size_t)1].neurons[j].propagationError * layers[i + (size_t)1].neurons[j].derivative() * layers[i].neurons[k].output);
			}
		for (int j = 0; j < layers[i + (size_t)1].neurons.size(); j++) {
			double T = layers[i].getThreshold(j) + alpha * layers[i + (size_t)1].neurons[j].propagationError * layers[i + (size_t)1].neurons[j].derivative();
			layers[i].setThreshold(j, T);
		}
	}
}

double NeuralNet::deviation(std::vector<double>& trainData)
{
	double dev = 0.0;
	for (int i = 0; i < layers[layers.size() - 1].neurons.size(); i++){
		dev += pow(layers[layers.size() - 1].neurons[i].output - trainData[i], 2);
	}
	return 0.5 * dev;
}