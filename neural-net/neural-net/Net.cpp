// Net.cpp
// implementation file for Net class

#include "stdafx.h"
#include "Net.h"
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

// class constructor
Net::Net(const vector<int>& topology)
{
	// Define the number of layers in the neural network
	unsigned numLayers = topology.size();

	for (int layerNum = 0; layerNum < numLayers; layerNum++)
	{
		// Use standard container function to append a new layer
		// and push onto neuron matrix m_layers
		m_layers.push_back(Layer());
		int numOutputs = 0;

		// Determine the number of outputs in network layer
		if (layerNum == topology.size() - 1)
		{
			// The last layer of the network, no output is requied
			numOutputs = 0;
		}
		else
		{
			// number of outputs is the number of neurons in the next layer
			numOutputs = topology[layerNum + 1];
		}

		// Fill the new Layer with neurons; add a bias neuron to the layer
		for (int neuronNum = 0; neuronNum <= topology[layerNum]; neuronNum++)
		{
			// Use standard container function to access the last element
			// use puch-back to add new neuron
			m_layers.back().push_back(Neuron(numOutputs, neuronNum));
		}
	}
}

// virtual destructor
Net::~Net()
{}

void Net::feedForward(const vector<double>& input_values)
{
	// Verify input size is equal to number of neurons in the layer minue the bias
	assert(input_values.size() == m_layers[0].size()-1);

	// Use standard container function to assign input values to input neurons
	for (int i = 0; i < input_values.size(); i++)
	{
		m_layers[0][i].setOutputVal(input_values[i]);
	}

	// Forward propagate
	for (int layerNum = 1; layerNum <= m_layers.size(); layerNum++)
	{
		// Loop through each inner layer and instruct each layer feed data to the next layer
		for (int neuronNum = 0; neuronNum < m_layers[layerNum].size()-1; neuronNum++)
		{
			Layer& prevLayer = m_layers[layerNum - 1];	// reference to previous layer

			// Loop through each neuron and instruct the neuron to feed data to the next layer
			m_layers[layerNum][neuronNum].feedForward(prevLayer);
		}
	}
}

void Net::backPropagate(const vector<double>& target_values)
{
	// back propagate the neural network with data to train the neural net

	// Calculate overall net error (Root Mean Square of output neuron errors)

	// Calculate output layer gradients

	// Calculate gradients on hidden layers

	// For all layers from outputs to first hidden layer,
	// update connection weights
}

void Net::getResults(vector<double>& result_values) const
{}
