#include "Layer.h"

Layer::Layer()
{
	this->numNeurons = 3;
	_layerSetup();
}

Layer::Layer(unsigned int numNeurons)
{
	this->numNeurons = numNeurons;
	_layerSetup();
}

void Layer::_layerSetup()
{
	this->inputSize = 0;

	this->arr = (Neuron**)malloc(sizeof(Neuron*) * numNeurons);
	for (int i = 0; i < numNeurons; i++)
		arr[i] = new Neuron();

	this->potentials = (double*)malloc(sizeof(double) * numNeurons);
	this->outputs = (double**)malloc(sizeof(double*) * numNeurons);
	for (int i = 0; i < numNeurons; i++)
		outputs[i] = arr[i]->getOutput();
}

void Layer::setInputs(double** inputs, unsigned int inputSize)
{
	this->inputSize = inputSize;

	for (int i = 0; i < numNeurons; i++)
		arr[i]->setInputs(inputs, inputSize);
}

void Layer::setWeights(double** inputWeights)
{
	for (int i = 0; i < this->numNeurons; i++)
		arr[i]->setWeights(inputWeights[i]);

}

void Layer::evaluate(double stepSize)
{
	for (int i = 0; i < numNeurons; i++)
	{
		arr[i]->evaluate(stepSize);
		arr[i]->caluclateOutput();
	}
}

double** Layer::getOutputs()
{
	return outputs;
}

void Layer::printNeurons()
{
	for (int i = 0; i < numNeurons; i++)
	{
		arr[i]->printNeuron();
	}
}

Layer::~Layer()
{
	free(arr);
	free(potentials);
	free(outputs);
}
