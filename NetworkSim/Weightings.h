#pragma once
#include <cstdlib>

class Weightings
{
public:
	Weightings(unsigned int inputs, unsigned int outputs);

	void setWeight(unsigned int input, unsigned int output, double weight);
	double getWeight(unsigned int input, unsigned int output);
	double** getWeights() { return weights; }
	unsigned int getOutputs() { return outputs; }

	~Weightings();

private:
	double** weights;
	unsigned int outputs, inputs;

};

