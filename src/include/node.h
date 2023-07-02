#ifndef MY_NEURAL_NETWORK_SRC_INCLUDE_NODE_H_
#define MY_NEURAL_NETWORK_SRC_INCLUDE_NODE_H_

class Node {
public:
    Node(int numInputs);
    void addInput(Node *newInput);
    double getValue();
protected:
    Node** inputs;
    int numInputs;
    int nextAvailInputSlot;
    double value;
};

#endif  // MY_NEURAL_NETWORK_SRC_INCLUDE_NODE_H_
