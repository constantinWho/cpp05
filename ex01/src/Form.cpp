#include "../inc/Form.hpp"

Form::Form(const std::string& name, const int requiredGrade, const int exeGrade) :
	_name(name), _signed(false), _requiredGrade(requiredGrade), _exeGrade(exeGrade) {
	if (_requiredGrade < 1 || _exeGrade < 1)
		throw GradeTooHighException();
	if (_requiredGrade > 150 || _exeGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getRequiredGrade() const { return _requiredGrade; }
int Form::getExeGrade() const { return _exeGrade; }

void Form::signForm(const Bureaucrat& mrBoss) {
	if (mrBoss.getGrade() > _requiredGrade)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& anmeldung) {
	out << "Form: " << anmeldung._name
		<< ", Signed: " << (anmeldung._signed ? "Yes" : "No")
		<< ", Sign Grade: " << anmeldung._requiredGrade
		<< ", Exec Grade: " << anmeldung._exeGrade;
	return out;
}

