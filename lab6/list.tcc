#include <algorithm>
#include <iostream>

#include "list.h"

template <class T>
void List<T>::insert(T const& d)
{
  first = new Link(d, first);
}

//-----------------------------------------------------//
// Important copy and assignment stuff


//class Link;

template <class T>
typename List<T>::Link* List<T>:: Link::clone(Link const* dolly)
{
  if ( dolly != nullptr )
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}
template <class T>
List<T>::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

template <class T>
List<T>::List(List const& l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}

template <class T>
List<T>::List(List<T>&& l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}

template <class T>
List<T>& List<T>::operator=(List<T> const& rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}

template <class T>
List<T>& List<T>::operator=(List&& rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}

template <class T>
bool List<T>::Iterator::operator!=(Iterator const rhs)
{
    return current_node != rhs.current_node;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
    if (current_node != nullptr)
    {
        current_node = current_node->next;
    }
    return *this;
}

template <class T>
T& List<T>::Iterator::operator*()
{
    return current_node->data;
}

template <class T>
typename List<T>::Iterator List<T>::begin() const
{
    return Iterator(first);
}

template <class T>
typename List<T>::Iterator List<T>::end() const
{
    return Iterator(nullptr);
}

template <class Hej>
std::ostream& operator<<(std::ostream& os, const List<Hej>& list)
{
    for (auto i : list)
    {
        os << i << " ";
    }
    os << std::endl;
    return os;
}
