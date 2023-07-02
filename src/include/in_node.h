#ifndef MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_
#define MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_

#include "include/node.h"

class InNode : public Node {
public:
    InNode();
    void setValue(double value);
};

#endif  // MY_NEURAL_NETWORK_SRC_INCLUDE_IN_NODE_H_
