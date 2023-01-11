
#ifndef PROJ10_1_PROJ10_NODE_H
#define PROJ10_1_PROJ10_NODE_H

template <class T>
class Node {
public:
    T data;
    Node <T>*next;

    Node( T d ) {
        data = d;
        next = NULL;
    }

    ~Node( ) {
        delete next;
    }
};

#endif //PROJ10_1_PROJ10_NODE_H
