#include "./inc/Bureaucrat.hpp"
#include "./inc/Form.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 70);
		Bureaucrat lice("Robert", 14);
		Form taxForm("Tax Form", 50, 25);

		std::cout << taxForm << std::endl;

		taxForm.signForm(alice);
		std::cout << taxForm << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
