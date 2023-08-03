#ifndef MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_
#define MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_

#include "node.h"

class InNode : public Node {
public:
    InNode(int numOutputs);
    ~InNode();
    void setValue(double value);
    void addOutput(Node *newOutput);
private:
    int numOutputs;
    int nextOutputSlot;
    Node **outputs;
};

#endif  // MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_
