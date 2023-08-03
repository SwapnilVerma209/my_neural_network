#include "include/in_node.h"
#include "include/node.h"

InNode::InNode(int numOutputs) : Node(), numOutputs(numOutputs),
        nextOutputSlot(0), outputs(nullptr) {
    if (numOutputs > 0) {
        this->outputs = new Node *[numOutputs];
        for (int i = 0; i < numOutputs; ++i) {
            this->outputs[i] = nullptr;
	}
    }	
} 

InNode::~InNode() {
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
