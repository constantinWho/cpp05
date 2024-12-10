#include "../inc/Form.hpp"

Form::Form(const std::string& name, int requiredGrade, int exeGrade)
	: _name(name), _signed(false), _requiredGrade(requiredGrade), _exeGrade(exeGrade) {
	if (requiredGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	if (requiredGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed),
	  _requiredGrade(other._requiredGrade), _exeGrade(other._exeGrade) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getRequiredGrade() const {
	return _requiredGrade;
}

int Form::getExeGrade() const {
	return _exeGrade;
}

void Form::signForm(const Bureaucrat& bureaucrat) {
	if (_signed)
		throw GradeTooLowException(); // Already signed
	if (bureaucrat.getGrade() > _requiredGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form: " << form.getName() << ", signed: " << (form.isSigned() ? "Yes" : "No")
	    << ", required grade: " << form.getRequiredGrade()
	    << ", execution grade: " << form.getExeGrade();
	return out;
}
