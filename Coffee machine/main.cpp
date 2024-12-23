#include <iostream>
#include <string>
#include "CoffeeMachine.h"

std::string GetDrinkName(DrinkType type) noexcept
{
	if (type == DrinkType::Cappuccino)
	{
		return "Cappuccino";
	}
	else if (type == DrinkType::Raf)
	{
		return "Raf";
	}
	else if (type == DrinkType::Latte)
	{
		return "Latte";
	}

	return "Invalid";
}

DrinkType CinDrinkType() noexcept
{
	std::string str{};
	std::cin >> str;

	auto drinkType{ DrinkType::Invalid };

	try
	{
		drinkType = static_cast<DrinkType>(std::stoi(str));
	}
	catch (const std::logic_error&)
	{
		// Ignore
	}

	return drinkType;
}


bool CheckOnValidDrink(DrinkType user_drink)
{
	return user_drink < DrinkType::Exit && user_drink > DrinkType::Invalid;
}

int main()
{
	std::cout << "Hi! Its coffee machine! Please input money: ";
	auto money{ 0 };
	std::cin >> money;

	std::cout << std::endl;

	CoffeeMachine machine{ 1.0, 1.0, 1.0, money };

	auto user_drink{ DrinkType::Invalid };
	while (static_cast<DrinkType>(user_drink) != DrinkType::Exit)
	{
		std::cout << "Choose coffee (1 - Cappuccino, 2 - Raf, 3 - Latte, 4 - exit): ";
		user_drink = CinDrinkType();

		if (!CheckOnValidDrink(user_drink))
		{
			std::cout << "Invalid drink!" << std::endl;
			continue;
		}

		Result res{ machine.ChoiceDrink(user_drink) };
		if (res == Result::OK)
		{
			std::cout << "Your Coffee: " << GetDrinkName(user_drink) << " is ready, Sir -> \n\n";
		}
		else if (res == Result::NoMoney)
		{
			std::cout << "Money is over!\n";
			break;
		}
		else if (res == Result::NoIngredients)
		{
			std::cout << "Ingredients is over. Please call administrator.\n";
			break;
		}
	}

	std::cout << "Bye bye!";
	return 0;
}
