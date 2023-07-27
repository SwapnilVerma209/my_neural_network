#include "include/in_node.h"
#include "include/node.h"

InNode::InNode(int numOutputs) : Node(), numOutputs(numOutputs),
        nextOutputSlot(0) {
    if (numOutputs <= 0) {
        this->outputs = nullptr;
    } else {
        this->outputs = new Node *[numOutputs];
    }	
} 

virtual InNode::~InNode() {
    delete [] outputs;
}

void InNode::setValue(double value) {
    this->value = value;
}

void InNode::addOutput(Node *newOutput) {
    if (this->nextOutputSlot >= this->numOutputs) {
        return;
    }
    this->outputs[this->nextOutputSlot++] = newOutput;
}
