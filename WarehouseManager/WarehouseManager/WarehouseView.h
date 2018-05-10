#pragma once
#include "Warehouse.h"
#include <SFML/Graphics.hpp>

class WarehouseView : public sf::Drawable {
private:
	const Warehouse* currentWarehouse;
	const Floor* currentFloor;
	uint32_t tileDrawSize = 32;
	sf::Texture whiteTexture;
	sf::Sprite noShelfSprite;
	sf::Sprite emptyShelfSprite;
	sf::Sprite occupiedShelfSprite;
public:
	WarehouseView();
	WarehouseView(const Warehouse* warehousePtr);
	void setWarehouse(const Warehouse* warehousePtr);
	void setCurrentlyDisplayedFloor(uint32_t floorId);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
