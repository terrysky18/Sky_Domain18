// neural-net.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Net.h"


int main()
{
	// Test code for neural net class

	// topology example: {3, 2, 1}
	std::vector<unsigned> topology;
	Net myNet(topology);

	std::vector<double> inputVals;
	myNet.feedForward(inputVals);

	std::vector<double> targetVals;
	myNet.backPropagate(targetVals);

	std::vector<double> resultVals;
	myNet.getResults(resultVals);

    return 0;
}

