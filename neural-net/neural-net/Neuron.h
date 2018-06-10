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
	Neuron(int numOutputs, int myIndex);
	virtual ~Neuron();

	void setOutputVal(const double input_value);
	double getOutputVal() const;
	void feedForward(const Layer& prevLayer_ptr);

private:
	double m_outputVal;
	int m_myIndex;	// index in the layer
	vector<Connection> m_outputWeights;

	// static member function to be shared
	static double randomWeight();
	static double transferFunction(double x);
	static double diffTransFunction(double x);
};

#endif // !NEURON_H
