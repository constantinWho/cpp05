#include "../inc/Intern.hpp"

// Constructor and destructor
Intern::Intern() {}
Intern::Intern(const Intern& other) { *this = other; }
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

// Form creation functions
static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// Form creation logic
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	struct FormType {
		std::string name;
		AForm* (*create)(const std::string&);
	};

	FormType formTypes[] = {
		{"shrubbery creation", &createShrubbery},
		{"robotomy request", &createRobotomy},
		{"presidential pardon", &createPardon}
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formTypes[i].name) {
			std::cout << "Intern creates " << formName << std::endl;
			return formTypes[i].create(target);
		}
	}

	std::cerr << "Error: form not found" << std::endl;
	return nullptr;
}
