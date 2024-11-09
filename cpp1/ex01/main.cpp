#include "Zombie.hpp"

int	main(void)
{
	int		N = 5;
	Zombie	*Zombies_heap;

	Zombies_heap = zombieHorde(N, "Zombie");
	if (Zombies_heap == NULL)
		return (EXIT_FAILURE);
	for (int i = 0; i < N; i++)
		Zombies_heap[i].announce();
	delete[] Zombies_heap;
	return (EXIT_SUCCESS);
}
