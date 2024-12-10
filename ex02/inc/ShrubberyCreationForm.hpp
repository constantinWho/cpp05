#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "./AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat& executor) const override;

private:
	std::string _target;
};

#endif
