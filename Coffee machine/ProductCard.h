#pragma once

enum class DrinkType
{
	Invalid,
	Cappuccino,
	Raf,
	Latte,
	Exit,
};

struct ProductCard final
{
	DrinkType ID{ DrinkType::Invalid };
	int		  Price{ };
	double	  Coffee{ };
	double	  Milk{ };
	double	  Sugar{ };

	ProductCard(DrinkType id, int price, double coffee, double milk, double sugar) noexcept :
		ID{ id },
		Price{ price },
		Coffee{ coffee },
		Milk{ milk },
		Sugar{ sugar }
	{
	}
};