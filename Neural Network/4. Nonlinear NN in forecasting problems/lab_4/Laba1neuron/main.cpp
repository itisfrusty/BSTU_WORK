#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "NeuralNet.h"

double sinFunction(double x) {
	double a = 0.2, b = 0.6, c = 0.05, d = 0.6;
	return a * cos(b * x) + c * sin(d * x);
}

int main()
{
	std::shared_ptr<ActivationFunction> sigmoid = std::shared_ptr<ActivationFunction>(new AFSigmoid());
	std::shared_ptr<ActivationFunction> linear = std::shared_ptr<ActivationFunction>(new AFLinear());

	int hiddenCount = 1, inputCount = 5, outputCount = 1;
	NeuralNet nn(inputCount, hiddenCount, 4, outputCount);

	nn.setActivationFunction(nn.layers[0], linear);
	for (size_t i = 0; i < hiddenCount; i++)
		nn.setActivationFunction(nn.layers[i + 1], sigmoid);
	nn.setActivationFunction(nn.layers[nn.layers.size() - 1], linear);

	std::vector<std::vector<double>> trainData;
	std::vector<std::vector<double>> inputData;

	std::vector<double> outputData;

	std::cout << "\nSTUDING" << std::endl;
	double time = 0.0;
	std::vector<double> set;
	std::vector<double> set2;
	int trainSize = 500;
	for (int i = 0; i < inputCount; i++) {
		set.push_back(sinFunction(time));
		time += 0.1;
	}
	for (int i = 0; i < outputCount; i++) {
		set2.push_back(sinFunction(time));
		time += 0.1;
	}
	for (int k = 0; k < trainSize; k++) {
		inputData.push_back(set);
		trainData.push_back(set2);
		set.erase(set.begin());
		set.push_back(sinFunction(time));
		set2.erase(set2.begin());
		set2.push_back(sinFunction(time + 0.1));
		time += 0.1;
	}
	double td = 200.0;
	while (td >= 0.0001)
	{
		td = 0;
		for (int i = 0; i < inputData.size(); i++) {
			nn.input(inputData[i]);
			nn.trainNetwork(trainData[i]);
			td += nn.deviation(trainData[i]);
		}
	}
	std::cout << "Total deviation: " << td << std::endl;
	std::cout << "\nTraining ends at " << time << " seconds." << std::endl;
	std::cout << "Attempt to prediction sin function from " << time << " seconds..." << std::endl;
	std::cout << "\tStandard\t\tOutput\t\t\tDeviation" << std::endl;
	outputData = nn.outputVector();
	time = double(rand() % 100);
	double E = 0;
	inputData.clear();
	trainData.clear();
	set.clear();
	set2.clear();

	for (int i = 0; i < inputCount; i++) {
		set.push_back(sinFunction(time));
		time += 0.1;
	}
	for (int i = 0; i < outputCount; i++) {
		set2.push_back(sinFunction(time));
		time += 0.1;
	}
	for (int k = 0; k < 50; k++) {
		inputData.push_back(set);
		trainData.push_back(set2);
		set.erase(set.begin());
		set.push_back(sinFunction(time));
		set2.erase(set2.begin());
		set2.push_back(sinFunction(time + 0.1));
		time += 0.1;
	}

	for (int i = 0; i < inputData.size(); i++) {
		nn.input(inputData[i]);
		outputData = nn.outputVector();
		E = 0.5 * pow(outputData.at(0) - trainData[i][trainData[i].size() - 1], 2);
		std::cout << "#" << i + 1 << "\t" << std::to_string(trainData[i][trainData[i].size() - 1]).substr(0, 7) << "\t\t\t"
			<< std::to_string(outputData.at(0)).substr(0, 7) << "\t\t\t" << std::to_string(E).substr(0, 7) << std::endl;
	}
	return 0;
}