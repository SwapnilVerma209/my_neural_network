#include <utility>

#include "include/node.h"
#include "include/perceptron.h"

Perceptron::Perceptron(int numInputs, int numOutputs) : Node(),
	numInputs(numInputs), nextInputSlot(0), numOutputs(numOutputs),
	nextOutputSlot(0), bias(0.0), biasPartDeriv(0.0), biasGradient(0.0),
	dotProduct(0.0), inputs(nullptr), outputs(nullptr), weights(nullptr),
	partialDerivs(nullptr), gradient(nullptr) {
    if (numInputs > 0) {
        this->inputs = new Node *[numInputs];
	this->weights = new double[numInputs];
	this->partialDerivs = new double[numInputs];
	this->gradient = new double[numInputs];
	for (int i = 0; i < numInputs; ++i) {
            this->inputs[i] = nullptr;
	    this->weights[i] = 0.0;
	    this->partialDerivs[i] = 0.0;
	    this->gradient[i] = 0.0;
	}
    }
    if (numOutputs > 0) {
        this->outputs = new std::pair<Node *, int>[numOutputs];
        for (int i = 0; i < numOutputs; ++i) {
            this->outputs[i] = std::pair<Node *, int>(nullptr, -1);
	}
    }
}

Perceptron::~Perceptron() {
    delete [] this->inputs;
    delete [] this->outputs;
    delete [] this->weights;
    delete [] this->partialDerivs;
    delete [] this->gradient;
}

void Perceptron::addInput(Node *newInput) {
    if (this->nextInputSlot >= this->numInputs) {
        return;
    }
    this->inputs[this->nextInputSlot++] = newInput;
}

void Perceptron::addOutput(Node *newOutput, int i) {
    if (this->nextOutputSlot >= this->numOutputs) {
        return;
    }
    std::pair<Node *, int> &newOutPair = this->outputs[this->nextOutputSlot++];
    newOutPair.first = newOutput;
    newOutPair.second = i;
}

void Perceptron::calcValAndPartDerivs() {
    this->calcDotProduct();
    this->threshFunc();
    for (int i = 0; i < this->numInputs; ++i) {
        this->threshPartDeriv(i);
    }
    this->threshPartDeriv(-1);
}

void Perceptron::calcGradient() {
    this->resetGradient();
    for (int i = 0; i < this->numOutputs; ++i) {
        std::pair<Node *, int> &output = this->outputs[i];
	double outputGradientComp =
	        static_cast<Perceptron *>(output.first)->getGradientComp(output.second);
	for (int j = 0; j < this->numInputs; ++j) {
            this->gradient[j] += this->partialDerivs[j] * outputGradientComp;
	}
	this->biasGradient += this->biasPartDeriv * outputGradientComp;
    }
}

void Perceptron::gradientDescent(double learningRate) {
    for (int i = 0; i < this->numInputs; ++i) {
        this->weights[i] -= this->inputs[i]->getValue() * learningRate *
	        this->gradient[i];
    }
    this->bias -= learningRate * this->biasGradient;
}

void Perceptron::gradientAscent(double learningRate) {
    for (int i = 0; i < this->numInputs; ++i) {
        this->weights[i] += this->inputs[i]->getValue() * learningRate *
	        this->gradient[i];
    }
    this->bias += learningRate * this->biasGradient;
}

double Perceptron::getGradientComp(int i) const {
    return this->gradient[i];
}

void Perceptron::calcDotProduct() {
    this->dotProduct = 0.0;
    for (int i = 0; i < numInputs; ++i) {
        this->dotProduct += this->inputs[i]->getValue() * this->weights[i];
    }
    this->dotProduct -= this->bias;
}

void Perceptron::resetGradient() {
    for (int i = 0; i < this->numInputs; ++i) {
        this->gradient[i] = 0.0;
    }
    this->biasGradient = 0.0;
}
