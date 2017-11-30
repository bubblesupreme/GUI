#pragma once
#include "GUILayer.h"

class ScrollingPanel : public GUILayer
{
public:
	ScrollingPanel(VideoMode maxScrollPanelSize, RenderWindow &Swindow, Vector2f scrFieldPosition, Vector2f scrFieldSize, Color scrFieldColor, GUIStyle *gst);

	Vector2i viewPosition;

	//RenderTexture scrTexture;
	Texture scrTexture;
	Image scrImage;

	Sprite scrField;
	Vector2f scrFieldPosition;
	Vector2f scrFieldSize;

	Color scrFieldColor;

	RenderWindow* window;
	RenderWindow crutch;

	virtual void DrawPanel();
};
