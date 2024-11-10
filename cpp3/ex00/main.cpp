#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Hero("Hero");
	
	Hero.attack("Villain");
	Hero.takeDamage(3);
	Hero.beRepaired(3);
	
	Hero.takeDamage(7);
	Hero.beRepaired(3);
	Hero.beRepaired(3);

	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(20);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);

	Hero.takeDamage(77);
	Hero.takeDamage(77);

	return (EXIT_SUCCESS);
}
