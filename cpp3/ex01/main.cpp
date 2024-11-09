#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Hero("Hero");
	
	
	Hero.attack("Villain");
	Hero.takeDamage(3);
	Hero.beRepaired(3);
	
	Hero.guardGate();
	
	return (EXIT_SUCCESS);
}
