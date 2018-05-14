#include "WarehouseView.h"

WarehouseView::WarehouseView() {
	this->currentWarehouse = nullptr;
	this->currentFloor = nullptr;
	sf::Image img;
	img.create(32, 32, sf::Color::White);
	this->whiteTexture.loadFromImage(img);

	this->noShelfSprite.setTexture(whiteTexture);

	this->emptyShelfSprite.setTexture(whiteTexture);
	emptyShelfSprite.setColor(sf::Color::Yellow);

	this->occupiedShelfSprite.setTexture(whiteTexture);
	occupiedShelfSprite.setColor(sf::Color::Blue);
}

WarehouseView::WarehouseView(const Warehouse* warehousePtr) : currentWarehouse(warehousePtr) {
	sf::Image img;
	img.create(tileDrawSize, tileDrawSize, sf::Color::White);
	this->whiteTexture.loadFromImage(img);
	
	this->noShelfSprite.setTexture(whiteTexture);
	
	this->emptyShelfSprite.setTexture(whiteTexture);
	emptyShelfSprite.setColor(sf::Color::Yellow);
	
	this->occupiedShelfSprite.setTexture(whiteTexture);
	occupiedShelfSprite.setColor(sf::Color::Blue);
}

void WarehouseView::setWarehouse(const Warehouse* warehousePtr) {
	this->currentWarehouse = warehousePtr;
}

void WarehouseView::setCurrentlyDisplayedFloor(uint32_t floorId) {
	if (currentWarehouse) {
		this->currentFloor = this->currentWarehouse->getFloor(floorId);
	}
}

void WarehouseView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (this->currentFloor && visible) {
		for (uint32_t row = 0; row < this->currentFloor->getWidth(); ++row) {
			states.transform = sf::Transform::Identity;
			states.transform.translate(row * tileDrawSize, 0);
			for (uint32_t col = 0; col < this->currentFloor->getHeight(); ++col) {
				Floor::Tile currentTile = this->currentFloor->getTile(row, col);
				if (currentTile == Floor::Tile::NoShelf) {
					target.draw(noShelfSprite, states);
				}
				else if (currentTile == Floor::Tile::EmptyShelf) {
					target.draw(emptyShelfSprite, states);
				}
				else if (currentTile == Floor::Tile::OccupiedShelf) {
					target.draw(occupiedShelfSprite, states);
				}
				states.transform.translate(0, tileDrawSize);
			}
		}
	}
}

void WarehouseView::handleEvent(sf::Event event) {
	if (!this->currentFloor && visible) {
		return;
	}
	if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			const GoodsCollection* goodsCollection = currentFloor->getGoodsCollection(event.mouseButton.x / 32, event.mouseButton.y / 32);
			goodsCollectionView.setGoodsCollection(goodsCollection);
		}
	}
}

void WarehouseView::update(float seconds) {
	goodsCollectionView.update(seconds);
}

void WarehouseView::setVisible(bool val) {
	visible = val;
}
