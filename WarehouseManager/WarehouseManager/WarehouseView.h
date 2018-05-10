#pragma once
#include "Warehouse.h"
#include <SFML/Graphics.hpp>

class WarehouseView : public sf::Drawable {
private:
	const Warehouse* currentWarehouse;
	sf::Texture whiteTexture;
	sf::Sprite whiteSquare;
public:
	WarehouseView();
	WarehouseView(const Warehouse* warehousePtr);
	void setWarehouse(const Warehouse* warehousePtr);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
