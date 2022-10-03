#pragma once
#include <cstdio>

#include "Queue.h"

class Neuron
{
public:
	Neuron();
	Neuron(double weight);

	void evaluate(double stepSize);
	void setInputs(double** inputs, unsigned int inputSize) 
	{ 
	this->inputs = inputs; 
	this->inputSize = inputSize;
	}

	void setWeights(double* weights) { this->weights = weights; }
	void caluclateOutput();
	double* getOutput();
	void printNeuron();

	~Neuron();

private:
	double v, u, a, b, c, d, t, h;
	double* weights;
	double** inputs;
	double output;
	unsigned int inputSize;

	Queue* pulseTimes;

};

