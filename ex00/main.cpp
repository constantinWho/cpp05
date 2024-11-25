#include "inc/Bureaucrat.hpp"

void testCopyConstructor() {
	std::cout << "\n--- Testing Copy Constructor ---" << std::endl;

	try {
	Bureaucrat original("Alice", 10);
	std::cout << "Original: " << original << std::endl;

	// Using copy constructor
	Bureaucrat copy(original);
	std::cout << "Copy: " << copy << std::endl;

	// Verify the copied object
	std::cout << "Ensuring copy is independent of original..." << std::endl;
	copy.decrementGrade(); // Decrease grade for the copy
	std::cout << "Original after copy change: " << original << std::endl;
	std::cout << "Copy after grade decrement: " << copy << std::endl;

	} catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
	}
}

void testCopyAssignment() {
	std::cout << "\n--- Testing Copy Assignment Operator ---" << std::endl;

	try {
	Bureaucrat original("Bob", 20);
	Bureaucrat assigned("Placeholder", 150); // Placeholder object
	std::cout << "Original: " << original << std::endl;
	std::cout << "Assigned (before assignment): " << assigned << std::endl;

	// Using assignment operator
	assigned = original;
	std::cout << "Assigned (after assignment): " << assigned << std::endl;

	// Verify the assigned object
	std::cout << "Ensuring assignment creates a separate object..." << std::endl;
	assigned.incrementGrade(); // Increment grade for the assigned object
	std::cout << "Original after assignment change: " << original << std::endl;
	std::cout << "Assigned after grade increment: " << assigned << std::endl;

	} catch (std::exception &e) {
	std::cerr << e.what() << std::endl;
	}
}

int main() {
	std::cout << "=== Bureaucrat Class Test ===" << std::endl;

	testCopyConstructor();
	testCopyAssignment();

	return 0;
}
