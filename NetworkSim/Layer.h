#pragma once
#include "Neuron.h"

class Layer
{
public:
	Layer();
	Layer(unsigned int numNeurons);

	void setInputs(double** inputs, unsigned int inputSize);
	void setWeights(double** inputWeights);	
	void setBiases(double** inputBiases);
	void evaluate(double stepSize);
	double** getOutputs();
	void printNeurons();

	~Layer();

private:

	void _layerSetup();

	Neuron** arr;
	double* potentials;
	double** outputs;
	unsigned int numNeurons, inputSize;
};

