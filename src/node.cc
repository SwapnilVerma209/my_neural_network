#include "include/node.h"

Node::Node() : value(0.0) {}

Node::~Node() {}

double Node::getValue() const {
    return this->value;
}
