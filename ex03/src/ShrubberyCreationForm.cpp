#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExeGrade())
		throw GradeTooLowException();

	std::ofstream ofs(_target + "_shrubbery");
	if (!ofs.is_open())
		throw std::ios_base::failure("Failed to create file");

	ofs << "	   ###\n"
		<< "	  #o###\n"
		<< "	#####o###\n"
		<< "   #o#\\#|#/###\n"
		<< "	###\\|/#o#\n"
		<< "	 # }|{  #\n"
		<< "	   }|{\n";

	ofs.close();
}
