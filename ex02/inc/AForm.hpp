#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_requiredGrade;
		const int			_exeGrade;

	protected:
		// Protected constructor for use by derived classes
		AForm(const std::string& name, int requiredGrade, int exeGrade);

	public:
		virtual ~AForm(); // Virtual destructor
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		// Getters
		const std::string&	getName() const;
		bool				isSigned() const;
		int					getRequiredGrade() const;
		int					getExeGrade() const;

		// Actions
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void		execute(const Bureaucrat& executor) const = 0; // Pure virtual

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

		// Friend for output
		friend std::ostream& operator<<(std::ostream& out, const AForm& form);
};

#endif
