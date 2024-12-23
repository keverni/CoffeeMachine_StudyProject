#pragma once

#include "Supplies.h"
#include "ProductCard.h"
#include <vector>

enum class Result
{
	OK,
	NoMoney,
	NoIngredients,
	NoProductCard,
};

class CoffeeMachine final
{
public:
	CoffeeMachine(double init_coffee, double init_milk, double init_sugar, int init_balance) noexcept;

	Result ChoiceDrink(DrinkType drink);

private:
	int						 m_Balance{ 0 };
	Supplies				 m_Supplies{};
	std::vector<ProductCard> m_ProductCards{};
};
