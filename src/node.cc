#include "include/node.h"

Node::Node(int numInputs) : inputs(nullptr), numInputs(numInputs),
        nextAvailInputSlot(0), value(0.0) {
    if (this->numInputs > 0) {
        thinputs = 
    }
}

void Node::addInput(Node *newInput) {
    if (nextAvailInputSlot >= numInputs) {
        return;
    }
    this->inputs[(this->nextAvailInputSlot)++] = newInput;
}

double Node::getValue() {
    return this->value;
}
