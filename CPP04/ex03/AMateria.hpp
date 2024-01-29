#pragma once

# include <iostream>
# include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected:
		std::string type;
	
	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(AMateria const& elem);
		virtual ~AMateria(void);
		AMateria& operator=(AMateria const& elem);

		std::string const & getType() const;
		void setType(std::string const & type);

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};