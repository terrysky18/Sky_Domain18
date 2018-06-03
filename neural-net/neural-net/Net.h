// Net.h
// header file for Net class

#ifndef NET_H
#define NET_H

#include "stdafx.h"
#include <vector>
#include "Neuron.h"

using std::vector;

// a layer of neurons
typedef vector<Neuron> Layer;

class Net
{
	// Simple implementation of neural net
public:
	// class constructor
	Net(const vector<int> &topology);
	// virtual destructor
	virtual ~Net();

	void feedForward(const vector<double> &input_values);
	void backPropagate(const vector<double> &target_values);
	void getResults(vector<double> &result_values) const;

private:
	// 2-dimensional matrix of Neurons, vector of vector: vector< vector<Neuron>>
	vector<Layer> m_layers;	// m_layers[layerNum][neuronNum]
};

#endif // !NET_H
