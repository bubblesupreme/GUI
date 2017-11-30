#pragma once
#include <map>
#include "../GUI/GUILayer.h"
#include "../GUI/ScrollingPanel.h"

enum WindowTabState
{
	opened = 0,
	closed = 1
};
//просто примите его существование как данность пока что, пользутесь им так же как написан ов handler.cpp (можете прост ctrl-c)
class WindowTab : ObservableGUI
{
private:
	std::vector<std::shared_ptr<GUILayer>> GUILayers;
	std::vector<std::shared_ptr<ScrollingPanel>> ScrollPanels;
	RenderWindow window;
public:
	//констуркутор, не парьтесь на этот счет, просто передавайте ему положение размеры
	//пока что вторые два аргумента передавайте (0,0) и (ширинаќкна, высотаќкна)
	//обрезание пол€ видимости все равно пока не работает :)
	std::shared_ptr<GUILayer> CreateGUILayer(Vector2f position_, Vector2f size_);
	std::shared_ptr<ScrollingPanel> CreateScrollPanel(VideoMode maxScrollPanelSize,Vector2f scrFieldPosition, Vector2f scrFieldSize, Color scrFieldColor, GUIStyle *gst);
	void Redraw();//единственна€ функци€ которую надо вызывать дл€ отрисовки, не трогаем ее
	WindowTab(VideoMode mode, char* name);
	WindowTabState state;
	//TODO
	//Ќ≈ƒќѕ»Ћ≈Ќј, Ќ≈ ё«ј“№ ѕќ ј!
	void removeElement(IDrawable* observer) override;
	void notifyAll(const sf::Event& event) const override;
	~WindowTab();
};

