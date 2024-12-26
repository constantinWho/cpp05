#include "./inc/ShrubberyCreationForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/PresidentialPardonForm.hpp"
#include "./inc/Bureaucrat.hpp"
#include "./inc/AForm.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 150);

		ShrubberyCreationForm shrubbery("Garden");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Ford Prefect");

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;

		// Signing and executing forms
		alice.signForm(shrubbery);
		alice.executeForm(shrubbery);

		alice.signForm(robotomy);
		alice.executeForm(robotomy);

		alice.signForm(pardon);
		alice.executeForm(pardon);

		// Attempt to execute a form without signing
		bob.executeForm(shrubbery); // Should throw an exception
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
