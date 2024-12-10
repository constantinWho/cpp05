#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();

	void execute(const Bureaucrat& executor) const;

private:
	std::string _target;
};

#endif // PRESIDENTIALPARDONFORM_HPP
