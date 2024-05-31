#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Constructor was called." << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor was called." << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other) {
	type = other.type;
	std::cout << "Copy constructor was called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other) {
	if (this != &other)
		std::cout << "Copy assigment operator was called." << std::endl;
	return *this;
}
