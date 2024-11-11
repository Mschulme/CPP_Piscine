#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int	main(void)
{
	ScavTrap Hero("Hero");
	
	Hero.attack("Villain");

    Hero.guardGate();

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
