#include "Neuron.h"

Neuron::Neuron()
{
	this->v = -70;
	this->u = 0.2*v;

	// tonic spiking parameters
	this->a = 0.02f;
	this->b = 0.2f;
	this->c = -65.0f;
	this->d = 6.0f;

	this->t = 6.0f;
	this->h = 10.0f;

	this->pulseTimes = new Queue(10);
}

void Neuron::evaluate(double stepSize)
{
	int input = 0;
	for (int i = 0; i < inputSize; i++)
		input += *inputs[i] * weights[i];

	v = v + stepSize * (0.04 * v * v + 5 * v + 140 - u + input);
	u = u + stepSize * a * (b * v - u);

	pulseTimes->updateElements(stepSize, t);

	if (v > 30)
	{
		v = c;
		u = u + d;

		pulseTimes->enqueue(0.0);
	}
}

void Neuron::caluclateOutput()
{
	output = pulseTimes->sizeVal() * h;
}

double* Neuron::getOutput()
{
	return &output;
}

void Neuron::printNeuron()
{
	printf("Potential: %d, Output: %d\n", (int)v, (int)*getOutput());
}

Neuron::~Neuron()
{
	pulseTimes->~Queue();
	free(pulseTimes);
}

