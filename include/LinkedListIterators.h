// @author G. Hemingway, copyright 2017
//
#ifndef _LINKEDLISTITERATORS_H
#define _LINKEDLISTITERATORS_H

/**
 * This header contains both the normal iterator and the const iterator for the
 * LinkedList container.  All of the methods for both classes should be self-explanitory
 *
 */
template <typename T>
class LinkedListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
public:
    LinkedListIterator();
    bool operator==(const LinkedListIterator<T>& rhs) const;
    bool operator!=(const LinkedListIterator<T>& rhs) const;
    T& operator*() const;
    T* operator->() const;
    LinkedListIterator<T>& operator++();
    LinkedListIterator<T> operator++(int);
    LinkedListIterator<T>& operator--();
    LinkedListIterator<T> operator--(int);

private:
    friend class LinkedList<T>;
    LinkedListNode<T>* mPtr;
    explicit LinkedListIterator(LinkedListNode<T>* ptr);
};

template <typename T>
class LinkedListConstIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
public:
    LinkedListConstIterator();
    bool operator==(const LinkedListConstIterator<T>& rhs) const;
    bool operator!=(const LinkedListConstIterator<T>& rhs) const;
    const T& operator*() const;
    const T* operator->() const;
    LinkedListConstIterator<T>& operator++();
    LinkedListConstIterator<T> operator++(int);
    LinkedListConstIterator<T>& operator--();
    LinkedListConstIterator<T> operator--(int);

private:
    friend class LinkedList<T>;
    LinkedListNode<T>* mPtr;
    explicit LinkedListConstIterator(LinkedListNode<T>* ptr);
};

#include "../src/LinkedListIterators.cpp"

#endif //_LINKEDLISTITERATORS_H
