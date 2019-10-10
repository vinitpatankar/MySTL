#include <iostream>

namespace mystd
{
class ReferenceCount
{
    private:
        int count; // Reference Count
    public:
        void addReference()
        {
            // Increment the reference count
            count++;
        }
        int subtractReference()
        {
            // Decrement the reference count
            return --count;
        }
        int getCount()
        {
            return count;
        }
};
template <typename T>
class shared_ptr
{
    public:
        shared_ptr()
        {
            // Create the Reference Counter object the first time shared_ptr is called
            rc = new ReferenceCount();
            rc->addReference();
        }
        shared_ptr(T* s):s(s)
        {
            // Create the Reference Counter object the first time shared_ptr is called
            rc = new ReferenceCount();
            rc->addReference();
        }
        shared_ptr(const shared_ptr& other):s(other.s), rc(other.rc)
        {
            // Copy Constructor 
            rc->addReference();
            std::cout << "Copy Constructor called, reference count = " << rc->getCount() << '\n';
        }
        shared_ptr& operator=(const shared_ptr& other)
        {
            // Assignment Operator
            if(this != &other)
            {
                s = other.s;
                rc = other.rc;
                rc->addReference();
                std::cout << "Assignment operator called, reference count = " << rc->getCount() << '\n';
            }
            return *this;
        }
        shared_ptr(shared_ptr&& other)
        {
            s = other.s;
            rc = other.rc;
            rc->addReference();
            std::cout << "Move Constructor called, reference count = " << rc->getCount() << '\n';
        }
        shared_ptr& operator=(shared_ptr&& other)
        {
            if(this != &other)
            {
                s = other.s;
                rc = other.rc;
                rc->addReference();
                std::cout << "Move Assignment operator called, reference count = " << rc->getCount() << '\n';
            }
            return *this;
        }
        ~shared_ptr()
        {
            if(rc->subtractReference() == 0)
            {
                std::cout << "Zero: In ~shared_ptr, reference count = " << rc->getCount() << " hence deleting..." << '\n';
                delete s;
                delete rc;
            }
            else
            {
                std::cout << "Non-Zero: In ~shared_ptr, reference count = " << rc->getCount() << '\n';
            }
        }
        T* operator->()
        {
            return s;
        }
        T& operator*()
        {
            return *s;
        }
    //private:
        T* s{nullptr}; // Pointer to Shape class
        ReferenceCount *rc{nullptr}; // Reference Counter
};
}
