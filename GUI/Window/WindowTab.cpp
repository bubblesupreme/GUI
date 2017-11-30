 #include "WindowTab.h"

std::shared_ptr<GUILayer> WindowTab::CreateGUILayer(Vector2f position_, Vector2f size_)
{
	GUILayers.push_back(std::shared_ptr<GUILayer>(new GUILayer(window, position_, size_)));
	return GUILayers[GUILayers.size() - 1];
}

std::shared_ptr<ScrollingPanel> WindowTab::CreateScrollPanel(VideoMode maxScrollPanelSize,Vector2f scrFieldPosition, Vector2f scrFieldSize, Color scrFieldColor, GUIStyle *gst)
{
	ScrollPanels.push_back(std::shared_ptr<ScrollingPanel>(new ScrollingPanel(maxScrollPanelSize, window,scrFieldPosition, scrFieldSize, scrFieldColor, gst)));
	return ScrollPanels[ScrollPanels.size() - 1];
}

void WindowTab::Redraw()
{
	if (state == opened)
	{
		window.clear();
		Event event;
		while (window.pollEvent(event))
		{
			notifyAll(event);
			if (event.type == Event::Closed)
			{
				window.close();
				state = closed;
			}
            else if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }
		}
		for (auto& layer : GUILayers)
			layer->Draw();
		for (auto& scrollpanel : ScrollPanels)
		{
			scrollpanel->DrawPanel();
		}
		window.display();
	}
}

WindowTab::WindowTab(VideoMode mode, char * name) : window (mode,name)
{
	state = opened;
}

void WindowTab::removeElement(IDrawable* observer)
{

}

void WindowTab::notifyAll(const sf::Event & event) const
{
	for (auto& layer : GUILayers)
		layer->handleEvent(event);
}

WindowTab::~WindowTab()
{
}
