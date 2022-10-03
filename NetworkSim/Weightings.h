#pragma once
#include <cstdlib>

class Weightings
{
public:
	Weightings(unsigned int inputs, unsigned int outputs);

	void setWeight(unsigned int input, unsigned int output, double weight);
	double getWeight(unsigned int input, unsigned int output);
	double getBias(unsigned int input, unsigned int output);
	double** getWeights() { return weights; }
	double** getBiases() { return biases; }
	unsigned int getOutputs() { return outputs; }

	~Weightings();

private:
	double** weights;
	double** biases;
	unsigned int outputs, inputs;

};

