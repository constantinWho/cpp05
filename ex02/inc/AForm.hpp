#ifndef AFORM_HPP
# define AFORM_HPP

# include "./Bureaucrat.hpp"

class AForm {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_requiredGrade;
		const int			_exeGrade;

	protected:
		void checkExecution(const Bureaucrat& executor) const;

	public:
		AForm(const std::string& name, const int requiredGrade, const int exeGrade);
		virtual ~AForm();

	const std::string&		getName() const;
	bool					isSigned() const;
	int						getRequiredGrade() const;
	int						getExeGrade() const;

	void					signForm(const Bureaucrat& mrBoss);
	virtual void			execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "AForm grade too high!";
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "AForm grade too low!";
			}
	};
	class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw() {
				return "AForm is not signed!";
		}
	};


	friend std::ostream&	operator<<(std::ostream& out, const AForm& anmeldung);
};

#endif
