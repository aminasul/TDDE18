//this is our cc file
#include "linked_list.h"
#include <iostream>
using namespace std;

// TODO Complementary work needed: for constructors, please use member initialization lists
Sorted_List::Node::Node()
  : data(0), next(nullptr)
{
}

Sorted_List::Node::Node(Node *next, int data)
{
  this = data(data);
  this = next(next);
}

Sorted_List::Node* Sorted_List::Node:: set_next(Node *ptr)
{
    return this;
}

Sorted_List::Node* Sorted_List::Node:: get_next()
{
    return this -> next;
}

Sorted_List::Node* Sorted_List::Node:: set_data(int value)
{
    data = value;
    return this;
}

int Sorted_List::Node:: get_data()
{
    return data;
}

void Sorted_List::Node:: printlist()
{
    if (next != nullptr)
    {
	cout << get_data() << " " << flush;
	next -> printlist();
    }
    else
    {
	cout << get_data() << endl;
    }
}


Sorted_List::Sorted_List()
  : head(nullptr)
{
}

//copy constructure
Sorted_List::Sorted_List(Sorted_List const& other)
{
    this -> deep_copy(other);
}

Sorted_List::~Sorted_List()
{
    Node * currentNode = head;
    while (currentNode != nullptr)
    {
	Node * nextNode = currentNode -> next;
    	delete currentNode;
    	currentNode = nextNode;
    }
}

//move constructur
Sorted_List::Sorted_List(Sorted_List&& other)
  : head(nullptr)
{
    *this = std::move(other);
}

//move assignment
Sorted_List& Sorted_List::operator=(Sorted_List&& other)
{
    if(this != &other)
    {
	Node * tmp = head;
	while (tmp)
	{
	    head = head -> get_next();
	    delete tmp;
	    tmp = head;
	}
	head = other.head;
	other.head = nullptr;
    }
    return *this;
}

void Sorted_List::deep_copy(const Sorted_List& l1)
{

    if (l1.head == nullptr)
	return;

    Node * tmp = l1.head;
    head = new Node();
    head -> set_data(tmp -> get_data());
    head -> set_next(nullptr);
    Node * current = head;
    tmp = tmp -> get_next();

    while (tmp != nullptr)
    {
    	current -> set_next (new Node(nullptr, tmp -> get_data()));
	current = current -> get_next();
       	tmp = tmp -> get_next();
    }
    tmp = nullptr;
    current = nullptr;
}

int Sorted_List::at(int value)
{
    Node * current = head;
    int counter{};
    if (current)
    {
    while (current != nullptr)
    {
	counter ++;
	if (current -> get_data() == value)
	{
	    return counter;
	}
	else
	{
	    current = current -> get_next();
	}

    }
    }
    else
	cout << "Element is not in the list" << endl;
}

Sorted_List& Sorted_List::operator=(const Sorted_List& l1)
{
    if(this == &l1)
	return *this;
    Node * tmp2 = head;
    while (tmp2)
    {
    	remove(tmp2 -> get_data());
    	tmp2 = tmp2 -> get_next();
    }
    deep_copy(l1);
    return *this;
}

bool Sorted_List::is_empty()
{
    return (head == nullptr);
}


int Sorted_List::size()
{
    int s{};
    Node * current = head;
    while (current != nullptr)
    {
	current = current -> get_next();
	s++;
    }
    current = nullptr;
    return s;
}

void Sorted_List:: printlist()
{
    if (is_empty())
    {
	cout << "There are no elements in the list!" << endl;
    }
    else
    {
	head -> printlist();
    }
}


Sorted_List::Node* Sorted_List::insert_helper(Node *current, int value) {

    if (current == nullptr || value < current -> get_data())
    {
	Node* tmp = new Node(current, value);
	current = tmp;
	tmp = nullptr;
	return current;
    }

    else
    {
       	current -> set_next(insert_helper(current -> get_next(), value));
	return current;
    }

}

void Sorted_List::insert(int value)
{
    head = insert_helper(head, value);

}

// TODO Complementary work needed: this function is very long, you can make it nuch shorter.
// Hint: just loop through the list and every iteration check if it is the correct value, if so then return it
void Sorted_List::remove(int value)
{
    if (is_empty())
    {
	cout << "There are no elements in the list!" << endl;
    }
    else
    {

	if (head -> get_data() == value)
	{
	    while (head != nullptr && head ->get_data() == value)
	    {
		Node * toDelete = head;
		head = head -> get_next();
		delete toDelete;
	    }

	}
	else
	{
	    Node* current = head;
	    if (current -> get_next() != nullptr && current -> get_next() -> get_data() == value)
	    {
		Node * toDelete = current -> get_next();
		current -> set_next(current -> get_next() ->get_next());
		delete toDelete;
	    }
	    else
	    {
		while (current -> get_next() != nullptr && current -> get_next() -> get_data() < value)
		{
		    current = current -> get_next();
		    if (current -> get_next() != nullptr && current ->get_next() ->  get_data() == value)
		    {
			Node * toDelete = current -> get_next();
			current -> set_next(current -> get_next() ->get_next());
			delete toDelete;

		    }

		}

	    }

	}
    }
}
