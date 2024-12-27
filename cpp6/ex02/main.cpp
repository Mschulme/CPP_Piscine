#include <ctime>
#include <cstdlib>
#include <iostream>

#include "class_A.hpp"
#include "class_B.hpp"
#include "class_C.hpp"

Base *generate(void)
{
    int r = std::rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    return new C;
}


/*
void identify(Base* p)

Parameter Type: A pointer to Base.

Behavior:
Since p is a pointer, it could be NULL. The function can check if p is NULL before proceeding.
Identifying the type usually involves calling dynamic_cast<Derived*>(p). If the cast succeeds (returns a non-NULL pointer), then p points to that derived type.
If the cast fails, dynamic_cast returns NULL, and you move on to check the next type.

Key Point: Working with pointers allows you to safely test for a NULL pointer and use pointer-based casts without exceptions.
*/


void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}


/*
void identify(Base& p)

Parameter Type: A reference to Base.

Behavior:
A reference cannot be NULL. You know p always refers to some valid object.
You cannot just return NULL on a failed cast, because dynamic_cast<Derived&>(p) doesn’t return NULL; it throws std::bad_cast if p is not actually a Derived.
To identify the type, you attempt a reference cast dynamic_cast<Derived&>(p) inside a try block. If it succeeds, p is that type. If it fails, you catch the exception and try another type.

Key Point: Because the parameter is a reference and no pointers may be used inside this function (as per the given constraints), you must rely on exception handling to detect failed casts.
*/


void identify(Base& p)
{
    // No pointers allowed in this function, so we use reference casting
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown" << std::endl;
}

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    Base *basePtr = generate();

    identify(basePtr);

    identify(*basePtr);

    delete basePtr;
    return (EXIT_SUCCESS);
}

/*
When you write delete basePtr; and basePtr points to a derived object, the correct, complete object destruction must be carried out. This involves calling the derived class’s destructor first, and then the destructors of its base classes.
If the base class destructor is not virtual, deleting through a pointer to the base class will invoke only the base class destructor and fail to call the derived destructor. This leads to undefined behavior and typically results in resource leaks or other errors.
By making the base class destructor virtual, the C++ runtime uses the dynamic type of the object to call the correct, most-derived destructor. In other words, the destructor call is dispatched polymorphically, ensuring that all parts of the derived object are properly destroyed.
*/
