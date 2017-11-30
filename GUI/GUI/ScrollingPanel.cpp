#include "ScrollingPanel.h"

ScrollingPanel::ScrollingPanel(VideoMode maxScrollPanelSize, RenderWindow &Swindow, Vector2f scrFieldPosition, Vector2f scrFieldSize_, Color scrFieldColor_, GUIStyle *gst)
	:GUILayer((this->crutch), scrFieldPosition, scrFieldSize)
{
	viewPosition = Vector2i(0, 30);

	crutch.create(maxScrollPanelSize, "");
	crutch.setVisible(false);

	window = &Swindow;
	scrFieldColor = scrFieldColor_;
	scrFieldSize = scrFieldSize_;

	scrField.setPosition(scrFieldPosition);
}

void ScrollingPanel::DrawPanel()
{

	crutch.clear(scrFieldColor);
	for (std::shared_ptr<IDrawable> bo : elements)
			bo->Draw();

	crutch.display();
	Vector2u windowSize = crutch.getSize();
	Texture texture;
	texture.create(windowSize.x, windowSize.y);
	texture.update(crutch);
	scrImage = texture.copyToImage();

	IntRect area(viewPosition.x,viewPosition.y,scrFieldSize.x,scrFieldSize.y);
	scrTexture.loadFromImage(scrImage, area);

	scrField.setTexture(scrTexture);
	window->draw(scrField);
}
