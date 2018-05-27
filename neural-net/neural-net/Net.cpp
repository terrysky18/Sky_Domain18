#include "stdafx.h"
#include "Net.h"
#include <vector>

using namespace std;

// class constructor
Net::Net(const vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();

	for (unsigned layerNum = 0; layerNum < numLayers; layerNum++)
	{
		// Create a new Layer and push onto neuron matrix m_layers
		m_layers.push_back(Layer());

		// Fill the new Layer with neurons; add a bias neuron to the layer
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; neuronNum++)
		{

		}
	}
}

// virtual destructor
Net::~Net()
{}

void Net::feedForward(const vector<double> &input_values)
{}

void Net::backPropagate(const vector<double> &target_values)
{}

void Net::getResults(vector<double> &result_values) const
{}
