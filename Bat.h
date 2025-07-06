#pragma once
#include "GameObject.h"

class Bat : public GameObject
{
protected:
	sf::RectangleShape shape;

	float speed = 500.f;
	sf::Vector2f direction;

	float minY = 0.f;
	float maxY = 0.f;

public:
	Axis control = Axis::Vertical1;

	Bat(const std::string& name = "");
	~Bat() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float rot) override;
	void SetScale(const sf::Vector2f& s) override;
	void SetOrigin(const sf::Vector2f& o) override;
	void SetOrigin(Origins preset) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetControl(Axis axis) { control = axis; }
	sf::FloatRect GetGlobalBounds() { return shape.getGlobalBounds(); }
};

