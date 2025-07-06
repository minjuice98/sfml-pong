#include "stdafx.h"
#include "Bat.h"

Bat::Bat(const std::string& name)
	: GameObject(name)
{
}

void Bat::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void Bat::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void Bat::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale(s);
}

void Bat::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);

}

void Bat::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(shape, preset);
	}
}

void Bat::Init()
{
	shape.setSize({ 10.f, 100.f });
	shape.setFillColor(sf::Color::White);
	SetOrigin(Origins::TC);
	Reset();
}

void Bat::Release()
{
}

void Bat::Reset()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	sf::Vector2f size = shape.getSize();
	minY = 0.f + size.y * 0.5f; 
	maxY = bounds.height - size.y;
}

void Bat::Update(float dt)
{
	direction.y = InputMgr::GetAxis(control);
	sf::Vector2f pos = GetPosition() + direction * speed * dt;
	pos.y = Utils::Clamp(pos.y, minY, maxY);
	SetPosition(pos);
}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
