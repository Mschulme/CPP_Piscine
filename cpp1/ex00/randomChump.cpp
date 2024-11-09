#include "Zombie.hpp"

void	randomChump(const std::string &name)
{
	Zombie Foo_stack(name);

	Foo_stack.announce();
}
