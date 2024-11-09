#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Hero("Hero");
	
	Hero.attack("Villain");
	Hero.takeDamage(3);
	Hero.beRepaired(3);
	
	Hero.takeDamage(7);
	Hero.beRepaired(3);
	
	Hero.takeDamage(7);
	Hero.beRepaired(3);

	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);
	Hero.beRepaired(0);	
	
	return (EXIT_SUCCESS);
}
