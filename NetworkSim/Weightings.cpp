#include "Weightings.h"

Weightings::Weightings(unsigned int inputs, unsigned int outputs)
{
	this->inputs = inputs;
	this->outputs = outputs;

	weights = (double**)malloc(sizeof(double*) * this->outputs);
	for (int i = 0; i < outputs; i++)
	{
		weights[i] = (double*)malloc(sizeof(double) * this->inputs);
		for (int j = 0; j < this->inputs; j++)
			weights[i][j] = 0.0f;
	}
}

void Weightings::setWeight(unsigned int input, unsigned int output, double weight)
{
	if (inputs > this->inputs || this->inputs < 1)
		return;
	if (outputs > this->outputs || this->outputs < 1)
		return;
	weights[output - 1][input - 1] = weight;
}

double Weightings::getWeight(unsigned int input, unsigned int output)
{
	if (inputs > this->inputs)
		return 0.0f;
	if (outputs > this->outputs)
		return 0.0f;
	return weights[output][input];
}

Weightings::~Weightings()
{
	for (int i = 0; i < outputs; i++)
		free(weights[i]);
	free(weights);
}
