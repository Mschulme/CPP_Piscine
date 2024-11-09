#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Foo_heap;

	Foo_heap = newZombie("Foo_heap");
	if (Foo_heap == NULL)
		return (EXIT_FAILURE);
	Foo_heap->announce();
	delete Foo_heap;

	std::cout << std::endl;

	randomChump("Foo_Stack");
	return (EXIT_SUCCESS);
}
