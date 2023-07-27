#ifndef MY_NEURAL_NETWORK_SRC_INCLUDE_OUT_NODE_H_
#define MY_NEURAL_NETWORK_SRC_INCLUDE_OUT_NODE_H_

#include "include/node.h"

class OutNode : public Node {
public:
    OutNode(int numInputs);
    virtual ~OutNode();
    void addInput(Node *newInput);
    virtual double getGradient(int i);
protected:
    int numInputs;
    int nextInputSlot;
    Node **inputs;
}

#endif  // MY_NEURAL_NETWORK_SRC_INCLUDE_OUT_NODE_H_
