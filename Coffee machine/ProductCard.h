#pragma once

constexpr int INIT_VALUE{ 0 };

enum class DrinkType
{
	Invalid,
	Cappuccino,
	Raf,
	Latte,
	Exit,
};

struct ProductCard
{
	DrinkType ID{ DrinkType::Invalid };
	int		  Price{ INIT_VALUE };
	double	  Coffee{ INIT_VALUE };
	double	  Milk{ INIT_VALUE };
	double	  Sugar{ INIT_VALUE };

	ProductCard(DrinkType id, int price, double coffee, double milk, double sugar) :
		ID(id),
		Price(price),
		Coffee(coffee),
		Milk(milk),
		Sugar(sugar)
	{
	}
};