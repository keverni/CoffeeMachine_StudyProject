#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(double init_coffee, double init_milk, double init_sugar, int init_balance) :
	m_Balance(init_balance)
{
	m_Supplies.Coffee = init_coffee ;
	m_Supplies.Milk = init_milk ;
	m_Supplies.Sugar = init_sugar;

	m_ProductCards.emplace_back(ProductCard{ DrinkType::Cappuccino, 100, 0.02, 0.05, 0.02 });
	m_ProductCards.emplace_back(ProductCard{ DrinkType::Raf,        180, 0.01, 0.08, 0.02 });
	m_ProductCards.emplace_back(ProductCard{ DrinkType::Latte,      165, 0.01, 0.1,  0.02 });
}

Result CoffeeMachine::ChoiceDrink(DrinkType drink)
{
	auto CheckBalance = [&](int money)
	{
		return (m_Balance - money) >= 0;
	};
	auto CheckIngredients = [&](double coffee, double milk, double sugar)
	{
		return ((m_Supplies.Sugar - sugar) >= 0 && (m_Supplies.Milk - milk) >= 0 && (m_Supplies.Coffee - coffee) >= 0);
	};

	for (const auto& coffee : m_ProductCards)
	{
		if (coffee.ID == drink)
		{
			if (CheckBalance(coffee.Price))
			{
				if (CheckIngredients(coffee.Coffee, coffee.Milk, coffee.Sugar))
				{
					m_Balance -= coffee.Price;

					m_Supplies.Coffee -= coffee.Coffee;
					m_Supplies.Milk   -= coffee.Milk;
					m_Supplies.Sugar  -= coffee.Sugar;

					return Result::OK;
				}

				return Result::NoIngredients;
			}

			return Result::NoMoney;
		}
	}

	return Result::NoProductCard;
}
