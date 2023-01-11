
#ifndef PROJ9_1_PROJ9_NODE_H
#define PROJ9_1_PROJ9_NODE_H

template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T e) {
        data = e;
        next = NULL;
    }
};

#endif
