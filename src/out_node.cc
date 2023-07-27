#include "include/node.h"
#include "include/out_node.h"

OutNode::OutNode(int numInputs) : Node(), numInputs(numInputs), nextInputSlot(0)
{
    if (numInputs <= 0) {
        this->inputs = nullptr;
    } else {
        this->inputs = new Node *[numInputs];
    }
}

virtual OutNode::~OutNode() {
    delete [] this->inputs;
}

void OutNode::addInput(Node *newInput) {
    if (this->nextInputSlot >= this->numInputs) {
        return;
    }
    this->inputs[this->nextInputSlot++] = newInput;
}

virtual double getGradient(int i) {
    return 1.0;
}
