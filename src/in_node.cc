#include "include/in_node.h"
#include "include/node.h"

InNode::InNode() : Node(0) {}

void InNode::setValue(double value) {
    this->value = value;
}
