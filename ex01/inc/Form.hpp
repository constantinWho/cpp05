#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "./Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_requiredGrade;
		const int			_exeGrade;

	public:
		Form(const std::string& name, int requiredGrade, int exeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getRequiredGrade() const;
		int					getExeGrade() const;

		void				signForm(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		friend std::ostream& operator<<(std::ostream& out, const Form& form);
};

#endif
