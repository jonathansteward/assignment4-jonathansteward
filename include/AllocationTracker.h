#ifndef _ALLOCATION_TRACKER_H_
#define _ALLOCATION_TRACKER_H_

#include <cstdint>
#include <iostream>

class AllocationTracker {
public:
    AllocationTracker()
        : mJunk(0)
    {
        ++mCount;
    }

    AllocationTracker(const AllocationTracker& src)
    {
        (void)(src);
        ++mCount;
    }

    ~AllocationTracker()
    {
        --mCount;
    }

    void nonConstMethod()
    {
        ++mJunk;
    }

    void* operator new(size_t size)
    {
        (void)(size);
        throw "single object new invoked";
    }

    void* operator new[](size_t size)
    {
        ++mArrayCount;
        return ::operator new[](size);
    }

    void operator delete(void* ptr)
    {
        (void)(ptr);
        throw "single object delete invoked";
    }

    void operator delete[](void* ptr)
    {
        --mArrayCount;
        ::operator delete[](ptr);
    }

    static uint32_t getCount()
    {
        return mCount;
    }

    static uint32_t getArrayCount()
    {
        return mArrayCount;
    }

private:
    // Static object counters
    static uint32_t mCount;
    static uint32_t mArrayCount;
    // Instance junk counter
    uint32_t mJunk;
};

std::ostream& operator<<(std::ostream& stream, const AllocationTracker& obj);

#endif
