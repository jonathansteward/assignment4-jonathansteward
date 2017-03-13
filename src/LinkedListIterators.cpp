//
// Created by Jonathan Steward on 3/11/17.
//
#ifndef _LINKEDLISTITERATORS_CPP
#define _LINKEDLISTITERATORS_CPP

#include "LinkedListIterators.h"
#include "LinkedListNode.h"

template <typename T> LinkedListIterator<T>::LinkedListIterator()
{
}

template <typename T> bool LinkedListIterator<T>::operator==(const LinkedListIterator<T>& rhs) const
{
    return mPtr == rhs.mPtr;
}

template <typename T> bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T>& rhs) const
{
    return !(*this == rhs);
}

template <typename T> T& LinkedListIterator<T>::operator*() const
{
    return mPtr->mItem;
}

template <typename T> T* LinkedListIterator<T>::operator->() const
{
    return mPtr;
}

template <typename T> LinkedListIterator<T>& LinkedListIterator<T>::operator++()
{
    ++mPtr;
    return *this;
}

template <typename T> LinkedListIterator<T> LinkedListIterator<T>::operator++(int)
{
    LinkedListIterator<T> tmp(*this);
    ++*this;
    return tmp;
}

template <typename T> LinkedListIterator<T>& LinkedListIterator<T>::operator--()
{
    --mPtr;
    return *this;
}

template <typename T> LinkedListIterator<T> LinkedListIterator<T>::operator--(int)
{
    LinkedListIterator<T> tmp(*this);
    --*this;
    return tmp;
}

template <typename T>
LinkedListIterator<T>::LinkedListIterator(LinkedListNode<T>* ptr)
    : mPtr(ptr)
{
}

// start const
template <typename T> LinkedListConstIterator<T>::LinkedListConstIterator()
{
}

template <typename T>
bool LinkedListConstIterator<T>::operator==(const LinkedListConstIterator<T>& rhs) const
{
    return mPtr == rhs.mPtr;
}

template <typename T>
bool LinkedListConstIterator<T>::operator!=(const LinkedListConstIterator<T>& rhs) const
{
    return !(*this == rhs);
}

template <typename T> const T& LinkedListConstIterator<T>::operator*() const
{
    return mPtr->mItem;
}

template <typename T> const T* LinkedListConstIterator<T>::operator->() const
{
    return mPtr;
}

template <typename T> LinkedListConstIterator<T>& LinkedListConstIterator<T>::operator++()
{
    ++mPtr;
    return (*this);
}
template <typename T> LinkedListConstIterator<T> LinkedListConstIterator<T>::operator++(int)
{
    LinkedListConstIterator<T> tmp(*this);
    ++*this;
    return tmp;
}

template <typename T> LinkedListConstIterator<T>& LinkedListConstIterator<T>::operator--()
{
    --mPtr;
    return *this;
}

template <typename T> LinkedListConstIterator<T> LinkedListConstIterator<T>::operator--(int)
{
    LinkedListConstIterator<T> tmp(*this);
    --*this;
    return tmp;
}

template <typename T>
LinkedListConstIterator<T>::LinkedListConstIterator(LinkedListNode<T>* ptr)
    : mPtr(ptr)
{
}

#endif //_LINKEDLISTITERATORS_CPP