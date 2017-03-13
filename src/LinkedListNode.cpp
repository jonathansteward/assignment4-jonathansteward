#ifndef _LINKED_LIST_NODE_CPP_
#define _LINKED_LIST_NODE_CPP_

#include "LinkedListNode.h"

/**
    * Initializes this node to store the provided item. The next and previous
    * pointers of this node are set to point to the node itself.
    * This operation provides strong exception safety.
    *
    * @param item the item to set
    */
template <typename T>
LinkedListNode<T>::LinkedListNode(const T& item)
    : mItem(item)
    , mPrev(this)
    , mNext(this)
{
}

/**
 * Destructor. Unlinks this node from its neighbors.
 * This operation is a no-throw.
 */
template <typename T> LinkedListNode<T>::~LinkedListNode() noexcept
{
    mPrev = nullptr;
    mNext = nullptr;
}

/**
     * Initializes this node with the provided values, i.e. the node stores
     * item, follows prev and precedes next in the linked list. Modifies prev
     * and next to maintain the linked list invariant. This operation provides
     * strong exception safety.
     *
     * @param item item to store in the node
     * @param prev pointer to the previous node
     * @param next pointer to the next node
     */
template <typename T>
LinkedListNode<T>::LinkedListNode(const T& item, LinkedListNode<T>* prev, LinkedListNode<T>* next)
    : mItem(item)
    , mPrev(prev)
    , mNext(next)
{
}

/**
 * Establishes the proper linkage between the provided nodes.
 *
 * @param   first node to link as preceding node
 * @param   second node to link as succeeding node
 * @post    first and second are linked in that order
 */
template <typename T>
void LinkedListNode<T>::link(LinkedListNode<T>* first, LinkedListNode<T>* second)
{
    first->mNext = second;
    second->mPrev = first;
}

#endif // _LINKED_LIST_NODE_CPP_