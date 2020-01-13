#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

//using Data = std::string;
//TODO Functions that can't change the object, either directley or indirectley should be const.(And those who can shnould not)


template <class T>
class List
{
public:
//	class Link;
	class Iterator;
         List();
	~List() { delete first; }

	void insert(T const& d);

        List(List const&);
	List(List&&);
	List& operator=(List const&);
	List& operator=(List&&);
	Iterator begin() const;
	Iterator end() const;
	template <class Hej>
	friend std::ostream& operator<<(std::ostream&, const List<Hej>&);

private:

	class Link
	{
	public:
	         Link(T const& d, Link* n)
			: data(d), next(n) {}
		~Link() { delete next; }

		friend class List;

		static Link* clone(Link const*);

	private:

		T data;
		Link* next;
	};

	Link* first;

public:

	using value_type = T;

	class Iterator
	{
	    friend List;
	public:
	    Iterator(Link* init) : current_node(init) {};
	    ~Iterator() { delete current_node; };
	    bool operator!=(Iterator const rhs);
	    Iterator& operator++();
	    T& operator*();

	private:
	    Link* current_node;
	};
	// Suitable place to add things...


};

#include "list.tcc"
#endif
