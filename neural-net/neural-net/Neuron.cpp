// Neuron.cpp
// implementaion file for Neuron class

#include "stdafx.h"
#include "Neuron.h"
#include <vector>
#include <cstdlib>

using std::vector;
using std::rand;

// class constructor
Neuron::Neuron(const int numOutputs)
{
	for (int con = 0; con < numOutputs; con++)
	{
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
}

// virtual destructor
Neuron::~Neuron()
{}

double Neuron::randomWeight()
{
	// Use random number generator to generate a random weight
	return (rand() / double(RAND_MAX));
}

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

}
