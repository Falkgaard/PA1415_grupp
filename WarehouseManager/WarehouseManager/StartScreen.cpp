#include "StartScreen.h"

StartScreen::StartScreen() {
	this->box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

	this->ipEntry = sfg::Entry::Create();
	ipEntry->SetRequisition(sf::Vector2f(200.f, 0.f));
	
	this->connectButton = sfg::Button::Create("connect");
	
	this->hostButton = sfg::Button::Create("host");

	box->SetSpacing(8.f);
	box->Pack(ipEntry);
	box->Pack(connectButton);
	box->Pack(hostButton);
	box->SetAllocation(sf::FloatRect(330,200,140,100));
	
	connectButton->GetSignal(sfg::Widget::OnLeftClick).Connect([&] { active = false; });
}

void StartScreen::handleEvent(sf::Event& e) {
	box->HandleEvent(e);
}

void StartScreen::update(float seconds) {
	box->Update(seconds);
}

bool StartScreen::isActive() const {
	return active;
}
