#include "./inc/Bureaucrat.hpp"
#include "./inc/Form.hpp"

int main() {
	try {
		std::cout << "---- Creating Bureaucrats ----" << std::endl;

		Bureaucrat high("HighRanker", 1);
		Bureaucrat low("LowRanker", 150);

		std::cout << high << std::endl;
		std::cout << low << std::endl;

		std::cout << "\n---- Testing Bureaucrat Exceptions ----" << std::endl;

		try {
			Bureaucrat invalidLow("TooLow", 200); // Invalid grade (too low)
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try {
			Bureaucrat invalidHigh("TooHigh", 0); // Invalid grade (too high)
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try {
			low.decrementGrade(); // Exceeding lowest grade
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try {
			high.incrementGrade(); // Exceeding highest grade
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\n---- Creating Forms ----" << std::endl;

		Form formA("FormA", 50, 50); // Valid form
		Form formB("FormB", 75, 75); // Valid form

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		std::cout << "\n---- Testing Form Exceptions ----" << std::endl;

		try {
			Form invalidFormHigh("TooHighForm", 0, 50); // Invalid required grade (too high)
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try {
			Form invalidFormLow("TooLowForm", 200, 150); // Invalid required grade (too low)
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\n---- Testing Signing ----" << std::endl;

		try {
			low.signForm(formA); // LowRanker cannot sign FormA
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		try {
			high.signForm(formB); // HighRanker signs FormB
			high.signForm(formB); // Attempting to re-sign
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\n---- Final Form States ----" << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
