#pragma once

# include <iostream>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain(void);
		Brain(Brain& elem);
		~Brain(void);

		Brain& operator=(const Brain& elem);

		std::string* getIdeas(void);
		void setIdeas(std::string ideas);
};
