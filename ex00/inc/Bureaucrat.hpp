#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>


class Bureaucrat {

	private:
		std::string	const _name;
		int			_grade;
	public:
		// Constructors and Destructor
		Bureaucrat();
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& other);
		~Bureaucrat();
};

#endif
