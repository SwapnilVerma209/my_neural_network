#ifndef MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_
#define MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_

#include <vector>

#include "include/node.h"

class InNode : public Node {
public:
    InNode(int numOutputs);
    virtual ~InNode();
    void setValue(double value);
    void addOutput(Node *newOutput);
protected:
    int numOutputs;
    int nextOutputSlot;
    Node **outputs;
};

#endif  // MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_
