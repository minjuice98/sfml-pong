#pragma once
#include "Scene.h"
#include "TextGo.h"

class Bat;
class Ball;

class SceneGame : public Scene
{
protected:
	Bat* bat1 = nullptr; //¿ÞÂÊ
	Bat* bat2 = nullptr; //¿À¸¥ÂÊ
	Ball* ball = nullptr;

	int score1 = 0; 
	int score2 = 0; 

	sf::Font font;
	sf::Text scoreText1;
	sf::Text scoreText2;

	bool ballActive = false;
public:
	SceneGame();
	~SceneGame() override = default;

	void Init() override;
	void Enter() override;
	void Update(float dt) override;
	void SetGameOver();
	void UpdateScoreText();
};

