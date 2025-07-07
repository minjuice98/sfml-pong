#pragma once
#include "Scene.h"
#include "TextGo.h"

class Bat;
class Ball;

class SceneGame : public Scene
{
protected:
	Bat* bat1 = nullptr; //����
	Bat* bat2 = nullptr; //������
	Ball* ball = nullptr;


	sf::Font font;
	sf::Text scoreText1;
	sf::Text scoreText2;

	bool ballActive = false;
public:
	int score1 = 0;
	int score2 = 0;

	SceneGame();
	~SceneGame() override = default;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;
	void SetGameOver();
	void UpdateScoreText();
	void Draw(sf::RenderWindow& window);
};