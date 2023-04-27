#include <iostream>
#include <windows.h>
#include <locale.h>
#include <vector>
#include <algorithm>
#include <variant>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

void func(std::variant<int, std::string, std::vector<int>> &var)
{

	if (std::holds_alternative<int>(var)) 
	{
		std::cout << std::get<int>(var) * 2;
	}
	if (std::holds_alternative<std::string>(var))
	{
		std::cout << std::get<std::string>(var);
	}
	if (std::holds_alternative<std::vector<int>>(var)) 
	{
		for (const auto& val: std::get<std::vector<int>>(var))
		{
			std::cout << val << " ";
		}
	}


}



int main(int argc, char** argv)
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::variant<int, std::string, std::vector<int>> var;

	var = get_variant();
	func(var);

}