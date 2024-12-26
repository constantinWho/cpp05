#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExeGrade())
		throw GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
