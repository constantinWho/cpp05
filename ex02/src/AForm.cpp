#include "../inc/AForm.hpp"

// Constructor
AForm::AForm(const std::string& name, int requiredGrade, int exeGrade)
	: _name(name), _signed(false), _requiredGrade(requiredGrade), _exeGrade(exeGrade) {
	if (requiredGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	if (requiredGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
}

// Destructor
AForm::~AForm() {}

// Copy Constructor
AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed),
	  _requiredGrade(other._requiredGrade), _exeGrade(other._exeGrade) {}

// Assignment Operator
AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_signed = other._signed; // Only copy `_signed`
	return *this;
}

// Getters
const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getRequiredGrade() const { return _requiredGrade; }
int AForm::getExeGrade() const { return _exeGrade; }

// Be Signed
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _requiredGrade)
		throw GradeTooLowException();
	_signed = true;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

// Stream Insertion Operator
std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << "Form: " << form.getName()
		<< ", Signed: " << (form.isSigned() ? "Yes" : "No")
		<< ", Required Grade to Sign: " << form.getRequiredGrade()
		<< ", Required Grade to Execute: " << form.getExeGrade();
	return out;
}

