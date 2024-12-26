#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm; // Forward declaration

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form);
    void executeForm(const AForm& form) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    friend std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
};

#endif
