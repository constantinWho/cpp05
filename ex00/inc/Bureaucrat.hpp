#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat {

	private:
		std::string	const		_name;
		int						_grade;

	public:
		Bureaucrat( const std::string& name, int grade);
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& other);
		~Bureaucrat();

		const std::string&		getName() const;
		int						getGrade() const;

		void					incrementGrade();
		void					decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too high!";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too low!";
				}
		};

		friend std::ostream&	operator<<(std::ostream& out, const Bureaucrat& auslanderBehorde);
};

#endif
