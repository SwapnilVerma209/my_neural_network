#ifndef MY_NEURAL_NETWORK_SRC_INCLUDE_PERCEPTRON_H_
#define MY_NEURAL_NETWORK_SRC_INCLUDE_PERCEPTRON_H_

#include <utility>

#include "node.h"

class Perceptron : public Node {
public:
    Perceptron(int numInputs, int numOutputs);
    virtual ~Perceptron();
    void addInput(Node *newInput);
    void addOutput(Node *newOutput, int i);
    void calcValAndPartDerivs();
    void calcGradient();
    void gradientDescent(double learningRate);
    void gradientAscent(double learningRate);
    double getGradientComp(int i) const;
protected:
    int numInputs;
    int nextInputSlot;
    int numOutputs;
    int nextOutputSlot;
    double bias;
    double biasPartDeriv;
    double biasGradient;
    double dotProduct;
    Node **inputs;
    std::pair<Node *, int> *outputs;
            // int is the component that the output is going to for the node
    double *weights;
    double *partialDerivs;
    double *gradient;

    virtual void threshFunc() = 0;
    virtual void threshPartDeriv(int i) = 0;
    void calcDotProduct();
    void resetGradient();
};

#endif  // MY_NEURAL_NETWORK_SRC_INCLUDE_PERCEPTRON_H_
