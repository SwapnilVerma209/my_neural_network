#ifndef MY_NEURAL_NETWORK_SRC_INCLUDE_NODE_H_
#define MY_NEURAL_NETWORK_SRC_INCLUDE_NODE_H_

class Node {
public:
    Node();
    virtual ~Node();
    double getValue() const;
protected:
    double value;
};

#endif  // MY_NEURAL_NETWORK_SRC_INCLUDE_NODE_H_
