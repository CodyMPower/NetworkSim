#include <cstdio>
#include "Network.h"
#include "Weightings.h"

int main()
{
	double* inputs = new double(0.0f);
	double tau = 0.25;
	unsigned int numInputs = 1;
	unsigned int numOutputs = 3;
	unsigned int numLayers = 3;
	unsigned int* numNodes = (unsigned int*)malloc(sizeof(unsigned int) * numLayers);
	for (int i = 0; i < numLayers; i++)
		numNodes[i] = 3;

	Weightings** weights = (Weightings**)malloc(sizeof(Weightings*) * (numLayers + 1));
	
	weights[0] = new Weightings(1, numNodes[0]);
	weights[1] = new Weightings(numNodes[0], numNodes[1]);
	weights[2] = new Weightings(numNodes[1], numNodes[2]);
	weights[3] = new Weightings(numNodes[2], numOutputs);
	
	weights[0]->setWeight(1, 1, 1.0f);
	weights[0]->setWeight(1, 2, 1.0f);
	weights[0]->setWeight(1, 3, 1.0f);

	weights[1]->setWeight(1, 1, 1.0f / 3.0f);
	weights[1]->setWeight(1, 2, 1.0f / 3.0f);
	weights[1]->setWeight(1, 3, 1.0f / 3.0f);
	weights[1]->setWeight(2, 1, 1.0f / 3.0f);
	weights[1]->setWeight(2, 2, 1.0f / 3.0f);
	weights[1]->setWeight(2, 3, 1.0f / 3.0f);
	weights[1]->setWeight(3, 1, 1.0f / 3.0f);
	weights[1]->setWeight(3, 2, 1.0f / 3.0f);
	weights[1]->setWeight(3, 3, 1.0f / 3.0f);

	weights[2]->setWeight(1, 1, 1.0f / 3.0f);
	weights[2]->setWeight(1, 2, 1.0f / 3.0f);
	weights[2]->setWeight(1, 3, 1.0f / 3.0f);
	weights[2]->setWeight(2, 1, 1.0f / 3.0f);
	weights[2]->setWeight(2, 2, 1.0f / 3.0f);
	weights[2]->setWeight(2, 3, 1.0f / 3.0f);
	weights[2]->setWeight(3, 1, 1.0f / 3.0f);
	weights[2]->setWeight(3, 2, 1.0f / 3.0f);
	weights[2]->setWeight(3, 3, 1.0f / 3.0f);

	weights[3]->setWeight(1, 1, 1.0f);
	weights[3]->setWeight(1, 2, 1.0f);
	weights[3]->setWeight(1, 3, 1.0f);

	

	Network* net = new Network();
	net->setInputs(&inputs,1);
	net->setWeights(weights);

	for (double time = 0; time < 100; time += tau)
	{
		if (time > 10)
			inputs[0] = 14;

		net->evaluate(tau);

		if ((int) time == time)
			net->printNeurons(time);
	}

	net->~Network();

	return 0;
}