//
// Created by killaz on 29.08.2024.
//

#ifndef LIST_H
#define LIST_H

#include <iostream>

template<typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* pNext;
        explicit Node(T data = T(), Node* pNext = nullptr) : data(data),pNext(pNext){}
    };
    size_t SIZE;
    Node* head;
public:
    List();
    ~List();
    size_t GetSize() const {return SIZE;}
    void push_back(T data);
    void pop_back();
    void print_list();
    void clear();
    void pop_front();
    void push_front(T data);
    void insert(T data,size_t index);
    void removeAt(size_t index);
    T& operator[](const size_t index);
};
template<typename T>
List<T>::List() {
    SIZE = 0;
    head = nullptr;
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node(data);
    }
    else {
        Node* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    SIZE++;
}

template<typename T>
void List<T>::print_list() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << ' ';
        current = current->pNext;
    }
    std::cout << std::endl;
}

template<typename T>
T& List<T>::operator[](const size_t index) {
    if (index >= SIZE) throw std::out_of_range("Out of range");
    Node* current = this->head;
    for (size_t i = 0; i < index; i++) {
        current = current->pNext;
    }
    return current->data;
}

template<typename T>
void List<T>::pop_front() {
    if (head == nullptr) return;
    Node* curr = head;
    head = head->pNext;
    delete curr;
    SIZE--;

}

template<typename T>
void List<T>::clear() {
    while(SIZE) {
        pop_front();
    }
}



template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node(data,head);
    SIZE++;
}

template<typename T>
void List<T>::insert(T data, size_t index) {
    if (index > SIZE) throw std::out_of_range("Out of range");
    else if (index == 0) {
        push_front(data);
    }
    else if (index == SIZE) {
        push_back(data);
    }
    else {
        Node* previous = this->head;
        for (size_t i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node* newNode = new Node(data,previous->pNext);
        previous->pNext = newNode;
        SIZE++;
    }
}

template<typename T>
void List<T>::removeAt(size_t index) {
    if (index >= SIZE) {
        throw std::out_of_range("RANGE ERROR");
    }
    else if (index == 0) {
        pop_front();
    }
    else {
        Node* previous = this->head;
        for (size_t i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        SIZE--;
    }
}

template<typename T>
void List<T>::pop_back() {
    removeAt(SIZE-1);
}




#endif //LIST_H
