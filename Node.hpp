#pragma once
#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
class Node {

public:
    T data;
    Node<T>* next;

    Node() : next(NULL) {
        data = NULL;
    }

    Node(T p_data) : next(NULL), data(p_data) {}
};

#endif 