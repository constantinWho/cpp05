#include "./inc/ShrubberyCreationForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/PresidentialPardonForm.hpp"

int main() {
    Bureaucrat alice("Alice", 1);
    ShrubberyCreationForm shrubbery("garden");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    alice.signForm(shrubbery);
    alice.executeForm(shrubbery);

    alice.signForm(robotomy);
    alice.executeForm(robotomy);

    alice.signForm(pardon);
    alice.executeForm(pardon);

    return 0;
}
