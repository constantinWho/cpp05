#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const override;

private:
	std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_HPP
