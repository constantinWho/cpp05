#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExeGrade())
		throw GradeTooLowException();

	std::cout << "* Drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
