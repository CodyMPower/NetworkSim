#include "Network.h"

Network::Network()
{
	numLayers = 3;
	numNeurons = (unsigned int*)malloc(sizeof(unsigned int) * numLayers);
	for (int i = 0; i < numLayers; i++)
		numNeurons[i] = 3;

	_networkSetup();
}

Network::Network(unsigned int numLayers)
{
	this->numLayers = numLayers;
	numNeurons = (unsigned int*)malloc(sizeof(unsigned int) * numLayers);
	for (int i = 0; i < numLayers; i++)
		numNeurons[i] = 3;

	_networkSetup();
}

Network::Network(unsigned int numLayers, unsigned int* numNeurons)
{
	this->numLayers = numLayers;
	this->numNeurons = numNeurons;

	_networkSetup();
}

void Network::setInputs(double** inputs, unsigned int inputSize)
{
	this->inputSize = inputSize;
	arr[0]->setInputs(inputs, inputSize);
}

void Network::setWeightsAndBiases(Weightings** weightings)
{
	numOutputs = weightings[numLayers]->getOutputs();
	for (int i = 0; i < numLayers; i++)
	{
		arr[i]->setWeights(weightings[i]->getWeights());
		arr[i]->setBiases(weightings[i]->getBiases());
	}

	outputs = (double*)malloc(sizeof(double) * numOutputs);
}

void Network::evaluate(double stepSize)
{
	for (int i = 0; i < numLayers; i++)
	{
		arr[i]->evaluate(stepSize);
	}
}

void Network::calculateOutputs()
{
	double output;
	for (int i = 0; i < numOutputs; i++)
	{
		output = 0;
		for (int j = 0; j < numNeurons[numLayers - 1]; j++)
			output += *(arr[numLayers - 1]->getOutputs()[j]);
		outputs[i] = output;
	}
}

void Network::printNeurons(double time)
{
	for (int i = 0; i < numLayers; i++)
		arr[i]->printNeurons();
	printf("Time: %d\n", (int)time);
}

Network::~Network()
{
	for (int i = 0; i < numLayers; i++)
		free(arr[i]);
	free(arr);
	free(numNeurons);
	free(outputs);
}

void Network::_networkSetup()
{
	arr = (Layer**)malloc(sizeof(Layer*) * numLayers);
	for (int i = 0; i < numLayers; i++)
		arr[i] = new Layer(numNeurons[i]);

	for (int i = 1; i < numLayers; i++)
		arr[i]->setInputs(arr[i-1]->getOutputs(), numNeurons[i-1]);
}
