#pragma once
#include <SFGUI/Widgets.hpp>
#include "GoodsCollection.h"
#include "GoodsCollectionController.h"

class GoodsCollectionView {
private:
	const GoodsCollection* goodsCollection;
	GoodsCollectionController controller;
	shared_ptr<sfg::Window> mainWindow;
	shared_ptr<sfg::ScrolledWindow> scrolledWindow;
	shared_ptr<sfg::Box> scrolledWindowBox;
	void fillWindow();
public:
	GoodsCollectionView();
	GoodsCollectionView(GoodsCollection* goodsCollection);
	void setController(GoodsCollectionController controller);
	void setGoodsCollection(const GoodsCollection* goodsCollection);
	void setVisible(bool val);
	void update(float seconds);
};