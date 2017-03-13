//
// Created by Graham Hemingway on 10/24/16.
//
#include "AllocationTracker.h"

uint32_t AllocationTracker::mCount = 0;
uint32_t AllocationTracker::mArrayCount = 0;

std::ostream& operator<<(std::ostream& stream, const AllocationTracker& obj)
{
    (void)(obj);
    stream << AllocationTracker::getCount() << std::endl;
    return stream;
}
