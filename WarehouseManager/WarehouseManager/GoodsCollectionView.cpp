#include "GoodsCollectionView.h"

GoodsCollectionView::GoodsCollectionView() {
	mainWindow = sfg::Window::Create();
	scrolledWindow = sfg::ScrolledWindow::Create();
	mainWindow->Add(scrolledWindow);
	scrolledWindowBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	mainWindow->SetRequisition(sf::Vector2f(200, 200));
	mainWindow->SetPosition(sf::Vector2f(400, 400));
	scrolledWindow->AddWithViewport(scrolledWindowBox);
	setVisible(false);
}

GoodsCollectionView::GoodsCollectionView(GoodsCollection* goodsCollection) {
	this->goodsCollection = goodsCollection;
	scrolledWindow = sfg::ScrolledWindow::Create();
	scrolledWindowBox = sfg::Box::Create();
	scrolledWindow->SetRequisition(sf::Vector2f(100, 100));
	fillWindow();
}

void GoodsCollectionView::fillWindow() {
	if (goodsCollection) {
		vector<Good> goods = goodsCollection->getGoods();
		for (const Good& good : goods) {
			auto newButton = sfg::Button::Create(good.getName());
			scrolledWindowBox->Pack(newButton);
		}
	}
}

void GoodsCollectionView::setGoodsCollection(const GoodsCollection* goodsCollection) {
	this->goodsCollection = goodsCollection;
	if (goodsCollection) {
		setVisible(true);
		fillWindow();
	}
	else {
		setVisible(false);
	}
}

void GoodsCollectionView::setVisible(bool val) {
	mainWindow->Show(val);
}

void GoodsCollectionView::update(float seconds) {
	mainWindow->Update(seconds);
}
