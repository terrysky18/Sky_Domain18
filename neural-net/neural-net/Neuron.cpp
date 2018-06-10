// Neuron.cpp
// implementaion file for Neuron class

#include "stdafx.h"
#include "Neuron.h"
#include <vector>
#include <cstdlib>
#include <cmath>

using std::vector;
using std::rand;
using std::tanh;

// class constructor
Neuron::Neuron(int numOutputs, int myIndex)
{
	for (int con = 0; con < numOutputs; con++)
	{
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
	m_myIndex = myIndex;
}

// virtual destructor
Neuron::~Neuron()
{}

// Mutator function
void Neuron::setOutputVal(const double input_value)
{
	m_outputVal = input_value;
}

// Accessor function
double Neuron::getOutputVal() const
{
	return m_outputVal;
}

void Neuron::feedForward(const Layer& prevLayer_ptr)
{
	double sum = 0.0;

	// Sum the previous layer's outputs
	// Include the bias neuron from the previous layer
	for (int n = 0; n < prevLayer_ptr.size(); n++)
	{
		// input value X weight
		sum += prevLayer_ptr[n].getOutputVal() * prevLayer_ptr[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = transferFunction(sum);
}

double Neuron::randomWeight()
{
	// Use random number generator to generate a random weight
	return (rand() / double(RAND_MAX));
}

double Neuron::transferFunction(double x)
{
	// Activation function of the neural network
	// tanh - output range [-1, 1]
	return tanh(x);
}

double Neuron::diffTransFunction(double x)
{
	// Derivative of the activation function
	// Using approximation of 1-tanh(x)**2
	return (1 - x * x);
}
