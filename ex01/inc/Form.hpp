#ifndef FORM_HPP
# define FORM_HPP

# include "./Bureaucrat.hpp"

class Form {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_requiredGrade;
		const int			_exeGrade;

	public:
		Form(const std::string& name, const int requiredGrade, const int exeGrade);
		~Form();

	const std::string&		getName() const;
	bool					isSigned() const;
	int						getRequiredGrade() const;
	int						getExeGrade() const;

	void					signForm(const Bureaucrat& mrBoss);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Form grade too high!";
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Form grade too low!";
			}
	};

	friend std::ostream&	operator<<(std::ostream& out, const Form& anmeldung);
};

#endif
