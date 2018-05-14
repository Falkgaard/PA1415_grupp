#pragma once
#include <SFGUI/Widgets.hpp>
#include "GoodsCollection.h"

class GoodsCollectionView {
private:
	const GoodsCollection* goodsCollection;
	shared_ptr<sfg::Window> mainWindow;
	shared_ptr<sfg::ScrolledWindow> scrolledWindow;
	shared_ptr<sfg::Box> scrolledWindowBox;
	void fillWindow();
public:
	GoodsCollectionView();
	GoodsCollectionView(GoodsCollection* goodsCollection);
	void setGoodsCollection(const GoodsCollection* goodsCollection);
	void setVisible(bool val);
	void update(float seconds);
};