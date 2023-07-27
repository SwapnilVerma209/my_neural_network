#include "include/node.h"

Node::Node() {}

virtual Node::~Node() {}

double Node::getValue() const {
    return this->value;
}
