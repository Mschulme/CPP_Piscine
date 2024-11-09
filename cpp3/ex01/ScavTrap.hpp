#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		std::string	Name;
		int			Hit_Points;
		int			Energy_Points;
		int			Attack_damage;
		
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap(void);
 		ScavTrap &operator=(const ScavTrap &obj);

		// member functions	
		void attack(const std::string& target);
		void guardGate(void);
};

