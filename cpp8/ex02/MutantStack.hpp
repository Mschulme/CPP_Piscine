#include <list>
#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    /*
    When you write something like Container::iterator inside a template class or function, the C++ compiler does not initially know whether iterator is a type or a static member. The keyword typename is necessary to tell the compiler, “I am referring to a type that depends on a template parameter (i.e., Container)”.
    Without typename, you might get a compiler error such as “need ‘typename’ before dependent type name” or something similar.
    */

    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        iterator begin()
        {
            return this->c.begin(); // Protected data member in the stack implementation.
        }

        iterator end()
        {
            return this->c.end();
        }

        const_iterator begin() const
        {
            return this->c.begin();
        }

        const_iterator end() const
        {
            return this->c.end();
        }

        // Reverse iterator

        reverse_iterator rbegin()
        {
            return this->c.rbegin();
        }

        reverse_iterator rend()
        {
            return this->c.rend();
        }

        const_reverse_iterator rbegin() const
        {
            return this->c.rbegin();
        }

        const_reverse_iterator rend() const
        {
            return this->c.rend();
        }
};


/*
typedef/using: Create an alias (a shorter, more convenient name) for an existing type.

typename: Required when referring to a dependent type in a template, to indicate that the thing after typename is a type, not a static data member.

iterator, const_iterator, etc.: Useful shortcuts to expose the underlying container’s iteration capabilities in your derived class
*/