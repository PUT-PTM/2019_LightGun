#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Graphics/Drawable.hpp>
#include<iostream>
using namespace sf;
using namespace std;
class Square : public sf::Drawable
{
public:
	Square(float X, float Y);
	Square() = delete;
	~Square() = default;
	void update();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	Vector2f getPosition();


	float left();
	float right();
	float top();
	float bottom();
private:
	
	RectangleShape shape;
	const Vector2f Size{ 60.0f,60.0f };
	const float squareVelo{ 3.1f };
	Vector2f velo{ squareVelo, squareVelo };
	void draw(RenderTarget& target, RenderStates state) const override;

};