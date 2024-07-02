#pragma once
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream> 
#include "Node.hpp"

using namespace std;

template<typename Type>
class LinkedList {
private:
    Node<Type>* head;
    int listSize;
public:
    LinkedList() : head(NULL), listSize(0) {}

    LinkedList(const LinkedList& list) {
        if (list.head != NULL) {
            clear();

            Node<Type>* cur = new Node<Type>();
            Node<Type>* cur2 = new Node<Type>();
            Node<Type>* newNode = new Node<Type>();
            listSize = list.listSize;

            cur = list.head;
            newNode->data = cur->data;
            newNode->next = NULL;
            head = newNode;
            cur2 = head;

            for (int i = 0; i < listSize - 1; i++) {
                cur = cur->next;
                newNode = new Node<Type>();
                newNode->data = cur->data;
                newNode->next = NULL;
                cur2->next = newNode;
                cur2 = cur2->next;
            }

            cur2->next = head;
        } else {
            head = NULL;
            listSize = 0;
        }
    }

    LinkedList(LinkedList&& list) {
        head = list.getHead();
        listSize = list.size();
        list.head = NULL;
        list.listSize = 0;
    }
    
    ~LinkedList() {
        clear();
    }

     void insertNode(Type data) {
            listSize++;
            Node<Type>* newNode = new Node<Type>(data);
            if (head == NULL) {
                head = newNode;
                head->next = head;
            }
            else if (head->next == head ){
                newNode->next = head;
                head->next = newNode;
                head = newNode;
            } else {
                newNode->next = head;
                Node<Type>* cur = head->next;
                while (cur->next != head)
                    cur = cur->next;
                cur->next = newNode;
                head = newNode;
            }            
     }

    void printList() {
        Node<Type>* temp = head;

        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }

        cout << temp->data << " ";
        temp = temp->next;
        while (temp != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    Type get(int id) {
        Node<Type>* cur1 = head;
        int count = 0;

        if (head != NULL)
          while (count < id) {
                count++;
                cur1 = cur1->next;
            }

        return cur1 != NULL ? cur1->data : NULL;
    }

    void deleteNode(int id) {
        Node<Type>* cur1 = head, * cur2 = head->next;
        int count = 0;
        if (id >= listSize && id != 0)
            id = id % listSize;

        if (head == NULL) {
            cout << "List empty." << endl;
        }
        else if (id == 0) {
            while (cur2->next != head)
                cur2 = cur2->next;
            cur2->next = head->next;
            cur1 = head->next;
            if (head != cur1) {
                delete head;
                head = cur1;
            }
            else {
                delete head;
                head = NULL;
            }
            listSize--;
        }
        else if (id > 0 && id < listSize) {
            while (id > 0) {
                cur2 = cur1;
                cur1 = cur1->next;
                id--;
            }

            cur2->next = cur1->next;
            delete cur1;

            listSize--;
        }
    }

    Node<Type>* cloneHead(Node<Type>& head2) {
        return head;
    }

    void clear() {
        Node<Type>* cur = head;
        if (cur != NULL) {
            while (cur->next != head)
                cur = cur->next;
            cur->next = NULL;

            while (head != NULL) {
                cur = head->next;
                delete head;
                head = cur;

            }
        }
    }

    int size() { 
        return listSize; 
    }

    const int max_size() {
        return 999; 
    }

    bool empty() { 
        return head == NULL; 
    }


    void setHead(Node<Type>*& otherHead) {
        clear();
        head = otherHead;
    }

    Node<Type>* getHead() { return head; }

    const LinkedList<Type>& operator=(const LinkedList<Type>& list) {
        if (list.head != NULL) {
            clear();
            Node<Type>* cur = new Node<Type>();
            Node<Type>* cur2 = new Node<Type>();
            Node<Type>* newNode = new Node<Type>();
            listSize = list.listSize;

            cur = list.head;
            newNode->data = cur->data;
            newNode->next = NULL;
            head = newNode;
            cur2 = head;

            for (int i = 0; i < listSize - 1; i++) {
                cur = cur->next;
                newNode = new Node<Type>();
                newNode->data = cur->data;
                newNode->next = NULL;
                cur2->next = newNode;
                cur2 = cur2->next;
            }

            cur2->next = head;
        }
        else {
            head = NULL;
            listSize = 0;
        }

        return *this;
    }

    bool operator==(const LinkedList<Type>& list) {
        if (list.listSize != listSize)
            return false;

        Node<Type>* cur = head;
        Node<Type>* curHead = list.head;

        if ((cur != NULL && curHead == NULL) || (cur == NULL && curHead != NULL) || cur->data != curHead->data)
            return false;

        cur = head->next;
        curHead = list.head->next;
        

        while (cur != head && cur->data == curHead->data) {
            cur = cur->next;
            curHead = curHead->next;
        }

        return cur == head;
    }

    bool operator!=(const LinkedList<Type>& list) {
        if (list.listSize != listSize)
            return false;

        Node<Type>* cur = head;
        Node<Type>* curHead = list.head;

        if ((cur != NULL && curHead == NULL) || (cur == NULL && curHead != NULL) || cur->data != curHead->data)
            return false;

        cur = head->next;
        curHead = list.head->next;


        while (cur != head && cur->data == curHead->data) {
            cur = cur->next;
            curHead = curHead->next;
        }

        return cur != head;
    }

    void swap(LinkedList<Type>& list1) {
        int sizee = list1.listSize;
        list1.listSize = listSize;
        listSize = sizee;

        Node<Type>* swapHead = head;
        head = list1.getHead();
        list1.head = swapHead;
    }

    void swap(LinkedList<Type>& list1, LinkedList<Type>& list2) {
        list1.swap(list2);
    }

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = Type;
        using pointer = Type*;
        using reference = Type&;

        Iterator(Node<Type>* ptr) : m_ptr(ptr) {}

        reference operator*() const { 
            return m_ptr->data; 
        }

        pointer operator->() { return m_ptr; }

        Iterator& operator++() { 
            m_ptr = m_ptr->next;
            return *this;  
        }

        Iterator operator++(int) { 
            Iterator tmp = *this; ++(*this); return tmp; 
        }

        Iterator& operator+=(difference_type offset) {
            for (difference_type i = 0; i < offset; ++i) {
                m_ptr = m_ptr->next;
            }

            return *this;
        }

        reference operator[](difference_type index) const {
            pointer tmp = m_ptr;
            for (difference_type i = 0; i < index; ++i) {
                tmp = tmp->next;
            }
            return tmp->value;
        }
        
        
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
        friend bool operator<(const Iterator& a, const Iterator& b) {
            pointer h = a.m_ptr;
            pointer tmp = h->next;
            while (tmp->next != h && tmp != b.m_ptr) {
                tmp = tmp->next;
            }
            return tmp == b.m_ptr;
        }
        friend bool operator>(const Iterator& a, const Iterator& b) { return b < a; }
        friend bool operator<=(const Iterator& a, const Iterator& b) { return !(b < a); }
        friend bool operator>=(const Iterator& a, const Iterator& b) { return !(a < b); }

    private:
        Node<Type>* m_ptr;
    };

    
    class constIterator {
        private:
            Node<Type>* curr;

        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = const Type;
            using pointer = const Type*;
            using reference = const Type&;
            using const_reference = value_type&;

            constIterator(Node<Type>* node) : curr(node) {}
            constIterator(const constIterator& iter) : curr(iter.curr) {}

            const_reference operator*() const { return curr->data; }
            constIterator& operator++() { curr = curr->next; return *this; }
            const Type* operator->() const { return &(curr->data); }
            bool operator==(const constIterator& other) const { return curr == other.curr; }
            bool operator!=(const constIterator& other) const { return !(*this == other); }
    };
    

    Iterator begin() { 
        return Iterator(head); 
    }

    Iterator end() {
        return NULL; 
    }

    const Iterator cbegin() {
        return constIterator(head);
    }

    const Iterator cend() {
        return NULL;
    }

    

    Iterator createIterator() {
        return begin();
    }

};

#endif 

