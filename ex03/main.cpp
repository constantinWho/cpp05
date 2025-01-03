#include <iostream>
#include "./inc/Intern.hpp"
#include "./inc/Bureaucrat.hpp"
#include "./inc/AForm.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 150);
		Intern intern;
		AForm* form;

		std::cout << "----- Valid Forms -----" << std::endl;

		// 1. ShrubberyCreationForm
		form = intern.makeForm("shrubbery creation", "Garden");
		if (form) {
			alice.signForm(*form);  // Alice has a high enough grade to sign.
			alice.executeForm(*form);  // Alice executes the form.
			delete form;  // Clean up to prevent memory leaks.
		}

		// 2. RobotomyRequestForm
		form = intern.makeForm("robotomy request", "Bender");
		if (form) {
			alice.signForm(*form);
			alice.executeForm(*form);
			delete form;
		}

		// 3. PresidentialPardonForm
		form = intern.makeForm("presidential pardon", "Ford Prefect");
		if (form) {
			alice.signForm(*form);
			alice.executeForm(*form);
			delete form;
		}

		std::cout << "\n----- Invalid Form -----" << std::endl;
		// 4. Invalid Form
		form = intern.makeForm("invalid form", "Target");
		if (!form) {
			std::cerr << "Intern could not create an unknown form." << std::endl;
		}

		std::cout << "\n----- Error Handling -----" << std::endl;
		// Attempting to have Bob (low grade) execute a signed form
		form = intern.makeForm("shrubbery creation", "Park");
		if (form) {
			alice.signForm(*form);  // Signed by Alice
			bob.executeForm(*form);  // Bob’s grade is too low to execute.
			delete form;
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
