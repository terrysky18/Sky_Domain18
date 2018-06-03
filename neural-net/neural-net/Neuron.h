// Neuron.h
// header file for Net class

#ifndef NEURON_H
#define NEURON_H

#include "stdafx.h"
#include <vector>

using std::vector;

struct Connection
{
	// Define the connection from a neuron to the next layer of neurons
	double weight;
	double deltaWeight;
};

class Neuron
{
	// a layer of neurons
	typedef vector<Neuron> Layer;

public:
	Neuron(const int numOutputs);
	virtual ~Neuron();

	void setOutputVal(const double input_value);
	double getOutputVal() const;
	void feedForward(const Layer& prevLayer_ptr);

private:
	double m_outputVal;
	vector<Connection> m_outputWeights;

	// static member function to be shared
	static double randomWeight();
};

#endif // !NEURON_H
