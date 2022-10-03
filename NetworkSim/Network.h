#pragma once
#include <cstdio>

#include "Layer.h"
#include "Weightings.h"

class Network
{
public:
	Network();
	Network(unsigned int numLayers);
	Network(unsigned int numLayers, unsigned int* numNeurons);

	void setInputs(double** inputs , unsigned int inputSize);
	void setWeights(Weightings** weightings);
	void evaluate(double stepSize);
	void calculateOutputs();
	double* getOutputs() { return outputs; }
	void printNeurons(double time);

	~Network();

private:
	void _networkSetup();

	Layer** arr;
	double* outputs;
	unsigned int numLayers, inputSize, numOutputs;
	unsigned int* numNeurons;
};

