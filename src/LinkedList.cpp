//
#ifndef _LINKED_LIST_CPP_
#define _LINKED_LIST_CPP_

#include <LinkedList.h>
#include <iostream>
#include <stdexcept>

/**
    * Initializes an empty LinkedList.
    * This operation provides strong exception safety.
    */
template <typename T>
LinkedList<T>::LinkedList()
    : mSize(0)
    , mTail(new LinkedListNode<T>())
{
}

/**
 * Initializes the LinkedList to be a copy of src.
 * This operation provides strong exception safety.
 *
 * @param src LinkedList to copy
 */
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& src)
    : mSize(src.mSize)
    , mTail(new LinkedListNode<T>)
{
    LinkedListConstIterator<T> iter;

    for (iter = src.begin(); iter != src.end(); ++iter) {
        add(iter.mPtr->mItem);
    }
}

/**
 * Makes this object a copy of rhs using the same guidelines as the copy
 * constructor. Note that calling this method on yourself (l = l;) is
 * equivalent to a no-op.
 * This operation provides strong exception safety.
 *
 * @param rhs LinkedList to copy
 * @return *this, used for chaining.
 */
template <typename T> const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    if (this != &rhs) {
        LinkedList<T> tmp(rhs);
        swap(tmp);
    }

    return *this;
}

/**
 * Destructor. Releases all resources held by this LinkedList.
 * This operation is no-throw under the assumption that the parameterizing
 * type's destructor is no-throw.
 */
template <typename T> LinkedList<T>::~LinkedList() noexcept
{
}

/**
 * Adds value to the end of this LinkedList. The insertion is performed in
 * constant time.
 * This operation provides strong exception safety.
 *
 * @param value value to append to this LinkedList
 */
template <typename T> void LinkedList<T>::add(const T& value)
{
    LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
    LinkedListIterator<T> iter = end();
    mTail->link(iter.mPtr, newNode);
    mTail->link(newNode, mTail.get());
    mSize++;
}

/**
 * Inserts value at the specified index. All elements at or to the right of
 * index are shifted down by one spot. Time proportional to the maximum of
 * the size of this LinkedList or index is needed to perform this operation.
 * In particular, note that this operation does not perform the tail
 * insertion optimization that add(const T& value) offers. If this
 * LinkedList needs to be enlarged (index is out of range) default values
 * are used to fill the gaps.
 * This operation provides strong exception safety.
 *
 * @param index index at which to insert value
 * @param value the element to insert
 */
template <typename T> void LinkedList<T>::add(uint32_t index, const T& value)
{
    if (index >= mSize) {
        uint32_t i = 0;
        uint32_t j = mSize - 1;
        while (i < (index - j)) {
            add(T());
            i++;
        }
        add(value);
    } else {
        uint32_t j = 0;
        LinkedListIterator<T> iter, iter2, iter3, iter4, iter5;
        iter3 = end();
        iter4 = iter3;
        iter3 = iter4--;
        iter3 = iter4--;
        T tmp, tmp2;
        for (iter = begin(); iter != iter3; ++j, ++iter) {
            if (iter == begin()) {
                iter2 = iter++;
            }
            if (j >= index) {
                if (j == index) {
                    tmp = iter2.mPtr->mItem;
                    iter2.mPtr->mItem = iter.mPtr->mItem;
                    iter2++;
                } else {
                    tmp2 = iter2.mPtr->mItem;
                    iter2.mPtr->mItem = tmp;
                    tmp = tmp2;
                    iter2++;
                }
            }
        }
        add(tmp2);
        uint32_t k = 0;
        iter5 = begin();
        while (k <= index) {
            if (k == index) {
                iter5.mPtr->mItem = value;
            }
            iter5++;
            k++;
        }
    }
}

/**
 * Empties this LinkedList returning it to the same state as the default
 * constructor.
 * This operation is no-throw under the assumption that the parametrizing
 * type's destructor is no-throw.
 */
template <typename T> void LinkedList<T>::clear() noexcept
{
    while (!isEmpty()) {
        remove(mSize - 1);
        mSize--;
    }
}

/**
 * Returns a constant reference to the element stored at the provided index.
 * If index is out of bounds, an std::out_of_range exception is thrown with
 * the index as its message.
 * This operation provides strong exception safety.
 *
 * @param index index of the element to return
 * @return constant reference to the element at the index.
 */
template <typename T> const T& LinkedList<T>::get(uint32_t index) const
{
    rangeCheck(index);

    LinkedListConstIterator<T> tmp;
    uint32_t j = 0;
    for (tmp = begin(); j < index; j++, ++tmp) {
    }

    return tmp.mPtr->mItem;
}

/**
 * Returns a reference to the element stored at the provided index. If index
 * is out of bounds, an std::out_of_range exception is thrown with the index
 * as its message.
 * This operation provides strong exception safety.
 *
 * @param index index of the element to return
 * @return reference to the element at the index.
 */
template <typename T> T& LinkedList<T>::get(uint32_t index)
{
    rangeCheck(index);

    LinkedListIterator<T> tmp;
    uint32_t j = 0;
    for (tmp = begin(); j < index; ++j, ++tmp) {
    }

    return *tmp;
}

/**
 * Returns true if and only if this LinkedList is logically equivalent to
 * rhs, i.e. the size and contents are equal.
 * This operation provides strong exception safety.
 *
 * @param rhs the LinkedList being compared to
 * @return true iff logically equivalent
 */
template <typename T> bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
    if (size() == rhs.size()) {
        uint32_t j = 0;
        for (LinkedListConstIterator<T> tmp = begin(), tmp2 = rhs.begin(); j < size();
             ++j, ++tmp, ++tmp2) {
            if (tmp.mPtr->mItem != tmp2.mPtr->mItem) {
                return true;
            }
        }
    }
    return false;
}

/**
 * Returns false if this LinkedList is equal to rhs and true otherwise.
 * This operation provides strong exception safety.
 *
 * @param rhs the LinkedList being compared to
 * @return true iff not logically equivalent
 */
template <typename T> bool LinkedList<T>::operator!=(const LinkedList<T>& rhs) const
{
    if (size() == rhs.size()) {
        for (LinkedListConstIterator<T> tmp = begin(), tmp2 = rhs.begin(); tmp2 != rhs.end();
             ++tmp, ++tmp2) {
            if (tmp.mPtr->mItem != tmp2.mPtr->mItem) {
                return false;
            }
        }
    }
    return true;
}

/**
     * Returns a constant iterator to the beginning.
     * This operation is a no-throw.
     *
     * @return
     */
template <typename T> LinkedListConstIterator<T> LinkedList<T>::begin() const noexcept
{
    return LinkedListConstIterator<T>(mTail->mNext);
}
/**
 * Returns an iterator to the beginning.
 * This operation is a no-throw.
 *
 * @return
 */
template <typename T> LinkedListIterator<T> LinkedList<T>::begin() noexcept
{
    return LinkedListIterator<T>(mTail->mNext);
}

/**
    * Returns a constant iterator to the end.
    * This operation is a no-throw.
    *
    * @return
    */
template <typename T> LinkedListConstIterator<T> LinkedList<T>::end() const noexcept
{
    return LinkedListConstIterator<T>(mTail->mPrev);
}
/**
 * Returns an iterator to the end.
 * This operation is a no-throw.
 *
 * @return
 */
template <typename T> LinkedListIterator<T> LinkedList<T>::end() noexcept
{
    return LinkedListIterator<T>(mTail->mPrev);
}

/**
 * Returns true if this LinkedList is empty and false otherwise.
 * This operation is a no-throw.
 *
 * @return
 */
template <typename T> bool LinkedList<T>::isEmpty() const noexcept
{
    return size() == 0;
}

/**
 * Removes the element at the specified index. If index is out of bounds
 * an std::out_of_range exception is thrown with index as its messaged. If
 * index points to the first or last element, this operation is performed in
 * constant time. Otherwise, time proportional to index is needed.
 * This operation is no-throw under the assumption that the parametrizing
 * type's destructor is no-throw.
 *
 * @param index index of the object to remove.
 */
template <typename T> void LinkedList<T>::remove(uint32_t index)
{
    rangeCheck(index);

    if (index == 0) {
        LinkedListIterator<T> tmp = begin();
        LinkedListIterator<T> tmp2 = tmp;
        // tmp.mPtr->mNext = tmp.mPtr->mNext->mNext;
        // tmp.mPtr->mNext->mPrev = tmp.mPtr->mPrev;
        mTail->link(mTail->mNext, tmp.mPtr->mNext->mNext);

        // mTail->mNext = tmp.mPtr;
        delete tmp2.mPtr;
        mSize--;
    } else if (index == mSize - 1) {
        LinkedListIterator<T> tmp = end();
        // LinkedListIterator<T> tmp2 = tmp;
        // tmp.mPtr = tmp.mPtr->mPrev;
        // tmp.mPtr->mNext = tmp2.mPtr->mNext;
        mTail->link(tmp.mPtr->mPrev, mTail.get());
        // mTail->mPrev = mTail->mPrev->mPrev;
        // mTail->mPrev->mNext = mTail;
        delete tmp.mPtr;
        mSize--;
    } else {
        uint32_t j = 0;
        for (LinkedListIterator<T> tmp = begin(); j <= index; ++j, ++tmp) {
            if (j == index) {
                LinkedListIterator<T> tmp2 = tmp;
                LinkedListIterator<T> tmp3 = tmp;
                tmp2.mPtr = tmp.mPtr->mPrev;
                tmp3.mPtr = tmp.mPtr->mNext;
                tmp2.mPtr->mNext = tmp3.mPtr;
                tmp3.mPtr->mPrev = tmp2.mPtr;
                delete tmp.mPtr;
                mSize--;
            }
        }
    }
}

/**
 * Sets the element at the specified index to the provided value. If index
 * is out of bounds, an std::out_of_range exception is thrown with the index
 * as its message. This method completes in time proportional to index.
 * This operation provides strong exception safety.
 *
 * @param index index of the object to set
 * @param value the new value
 */
template <typename T> void LinkedList<T>::set(uint32_t index, const T& value)
{
    rangeCheck(index);

    uint32_t j = 0;
    for (LinkedListIterator<T> i = begin(); j <= index; j++, ++i) {
        if (j == index) {
            i.mPtr->mItem = value;
        }
    }
}

/**
 * Return the size of this LinkedList.
 * This operation is a no-throw.
 *
 * @return
 */
template <typename T> uint32_t LinkedList<T>::size() const noexcept
{
    return mSize;
}

/**
     * Given an index, this method throws an std::out_of_range with the index as
     * its message if index is out of bounds or is a no-op otherwise.
     * This operation provides strong exception safety.
     *
     * @param index index to check
     */
template <typename T> void LinkedList<T>::rangeCheck(uint32_t index) const
{
    LinkedListConstIterator<T> iter;
    uint32_t j = 0;
    if (index >= mSize) {
        for (iter = begin(); j <= index; ++j, ++iter) {
            if (j == index) {
                // std::ostream_iterator<int> output(std::cout, "");
                // throw std::out_of_range(std::to_string(std::copy(iter, iter, output)));
                // std::copy(iter, iter, throw std::out_of_range(std::to_string(index)));
                throw std::out_of_range(std::to_string(index));
            }
        }
    }
}

/**
 * Removes from this LinkedList the node pointed to by iter.
 * This operation is no-throw under the assumption that the parametrizing
 * type's destructor is no-throw.
 *
 * @param iter iterator pointing to the node that should be removed.
 */
template <typename T> void LinkedList<T>::removeNode(iterator iter) noexcept
{
    std::unique_ptr<LinkedListNode<T> > tmp = mTail;
    LinkedListIterator<T> i = begin();

    while (i != iter) {
        tmp = i.mPtr;
        ++i;
    }

    if (i == iter) {
        delete tmp;
        mSize--;
    }
}

/**
 * Swaps the contents of this LinkedList with that of other in constant time.
 * This operation is a no-throw.
 *
 * @param other the LinkedList to swap with
 */
template <typename T> void LinkedList<T>::swap(LinkedList<T>& other) noexcept
{
    std::swap(mSize, other.mSize);
    std::swap(mTail, other.mTail);
}

#endif //_LINKED_LIST_CPP_