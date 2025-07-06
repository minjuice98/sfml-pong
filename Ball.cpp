#include "stdafx.h"
#include "Ball.h"
#include "Bat.h"
#include "SceneGame.h"

Ball::Ball(const std::string& name)
	: GameObject(name)
{
}

void Ball::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	shape.setPosition(pos);
}

void Ball::SetRotation(float rot)
{
	GameObject::SetRotation(rot);
	shape.setRotation(rot);
}

void Ball::SetScale(const sf::Vector2f& s)
{
	GameObject::SetScale(s);
	shape.setScale(s);
}

void Ball::SetOrigin(const sf::Vector2f& o)
{
	GameObject::SetOrigin(o);
	shape.setOrigin(o);
}

void Ball::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	if (preset != Origins::Custom)
	{
		Utils::SetOrigin(shape, preset);
	}
}

void Ball::Init()
{
	shape.setRadius(10.f);
	shape.setFillColor(sf::Color::Yellow);
	SetOrigin(Origins::MC);
}

void Ball::Release()
{
}

void Ball::Reset()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
    SetPosition({ bounds.width * 0.5f, bounds.height * 0.5f });

    float radius = shape.getRadius();
    minX = bounds.left + radius;
    maxX = bounds.left + bounds.width - radius;
    minY = bounds.top + radius;
    maxY = bounds.top + bounds.height - radius;

	direction = { 0.f, 0.f };
	speed = 0.f;
}

void Ball::Update(float dt)
{
    sf::Vector2f pos = GetPosition() + direction * speed * dt;

    if (pos.x < minX || pos.x > maxX)
    {
        if (SCENE_MGR.GetCurrentSceneId() == SceneIds::Game)
        {
            SceneGame* scene = (SceneGame*)SCENE_MGR.GetCurrentScene();
            scene->SetGameOver();
        }
        return;
    }

    if (pos.y < minY)
    {
        pos.y = minY;
        direction.y *= -1.f;
    }
    else if (pos.y > maxY)
    {
        pos.y = maxY;
        direction.y *= -1.f;
    }

    if (bat1 != nullptr)
    {
        const sf::FloatRect& batBounds = bat1->GetGlobalBounds();
        if (shape.getGlobalBounds().intersects(batBounds))
        {
            pos.x = batBounds.left + batBounds.width + shape.getRadius();
            direction.x = std::abs(direction.x); 
            direction.y *= -1.f;
        }
    }
    if (bat2 != nullptr)
    {
        const sf::FloatRect& batBounds = bat2->GetGlobalBounds();
        if (shape.getGlobalBounds().intersects(batBounds))
        {
            pos.x = batBounds.left - shape.getRadius();
            direction.x = -std::abs(direction.x);
            direction.y *= -1.f;
        }
    }
    SetPosition(pos);

}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Ball::Fire(const sf::Vector2f& d, float s)
{
	direction = d;
	speed = s;
}
