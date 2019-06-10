#include "pch.h"
#include "square.h"
using namespace sf;
using namespace std;

Square::Square(float X, float Y)
{
	shape.setPosition(X, Y);
	shape.setSize(this->Size);
	shape.setFillColor(Color::White);
	

}

void Square::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Square::update()
{
	shape.move(this->velo);

	if (this->left() < 0)
	{
		velo.x = squareVelo;
	}
	else if (this->right() > 800)
	{
		velo.x = -squareVelo;
	}

	if (this->top() < 0)
	{
		velo.y = squareVelo;
	}
	else if (this->bottom() > 600)
	{
		velo.y = -squareVelo;
	}
}

float Square::left()
{
	return this->shape.getPosition().x - shape.getSize().x;
}

float Square::right()
{
	return this->shape.getPosition().x + shape.getSize().x;
}

float Square::top()
{
	return this->shape.getPosition().y - shape.getSize().y;
}

float Square::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y;
}

void Square::moveDown()
{
	this->velo.y = squareVelo;
}
void Square::moveUp() {
	this->velo.y = -squareVelo;
}
void Square::moveRight() {
	this->velo.x = squareVelo;
}
void Square::moveLeft() {
	this->velo.x = -squareVelo;
}

Vector2f Square::getPosition()
{
	return shape.getPosition();
}