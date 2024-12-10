#include "../inc/AForm.hpp"

AForm::AForm(const std::string& name, const int requiredGrade, const int exeGrade) :
	_name(name), _signed(false), _requiredGrade(requiredGrade), _exeGrade(exeGrade) {
	if (_requiredGrade < 1 || _exeGrade < 1)
		throw GradeTooHighException();
	if (_requiredGrade > 150 || _exeGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getRequiredGrade() const { return _requiredGrade; }
int AForm::getExeGrade() const { return _exeGrade; }

void AForm::signForm(const Bureaucrat& mrBoss) {
	if (mrBoss.getGrade() > _requiredGrade)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const {
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _exeGrade)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& anmeldung) {
	out << "Form: " << anmeldung._name
		<< ", Signed: " << (anmeldung._signed ? "Yes" : "No")
		<< ", Sign Grade: " << anmeldung._requiredGrade
		<< ", Exec Grade: " << anmeldung._exeGrade;
	return out;
}

