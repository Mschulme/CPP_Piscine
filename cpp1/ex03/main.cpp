#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon club("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other typ of club");
		bob.attack();
	}

	std::cout << std::endl;

	{
		Weapon club("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (EXIT_SUCCESS);
}
