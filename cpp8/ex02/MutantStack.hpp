#include <list>
#include <stack>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        Container::iterator begin()
        {
            return this->c.begin();
        }

        Container::iterator end()
        {
            return this-> c.end();
        }

        Container::const_iterator begin() const
        {
            return this->c.begin();
        }

        Container::const_iterator end() const
        {
            return this-> c.end();
        }
};
