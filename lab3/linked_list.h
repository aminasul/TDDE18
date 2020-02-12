//this is our header file
#ifndef SORTED_LIST
#include <string>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>
#define SORTED_LIST

class Sorted_List
{
public:
    Sorted_List();
    Sorted_List(const Sorted_List& other);
    Sorted_List(Sorted_List&& other);
    ~Sorted_List();
    bool is_empty() const;
    int size() const;
    void insert(int data);
    void printlist() const;
    void remove(int value);
    void deep_copy(const Sorted_List& l);
    Sorted_List& operator =(const Sorted_List& l);
    Sorted_List& operator =(Sorted_List&& other);
    int at(int value) const;

    //Hejsan


private:
    class Node
    {
    public:
	Node();
	Node(Node *next, int data);
        int size() const;
        Node* get_next() const;
        int get_data() const;
	Node* set_data(int value);
	Node* set_next(Node *ptr);
        void printlist() const;
	int data;
	Node* next;
    };
    Node* insert_helper(Node *current, int data);
    Node* head;
};


//Sorted_List insert(Sorted_List const& l);

#endif
