#include "stdafx.h"
#include "SceneGame.h"
#include "Bat.h"
#include "Ball.h"

SceneGame::SceneGame() :Scene(SceneIds::Game)
{

}
void SceneGame::Init()
{
	bat1 = (Bat*)AddGameObject(new Bat("Bat1"));
	bat2 = (Bat*)AddGameObject(new Bat("Bat2"));
	ball = (Ball*)AddGameObject(new Ball("Ball"));
	
	bat1->SetControl(Axis::Vertical1);
	bat2->SetControl(Axis::Vertical2); 

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	bat1->SetPosition({ 20.f, bounds.height * 0.5f });
	bat2->SetPosition({ bounds.width - 20.f, bounds.height * 0.5f });
	bat1->Reset();
	bat2->Reset();

	ball->SetBat(bat1, bat2);


	Scene::Init();
}
void SceneGame::Enter()
{
	ballActive = false;

	Scene::Enter();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
	
	if (!ballActive)
	{
		sf::FloatRect batBounds = bat1->GetGlobalBounds();
		float ballRadius = 10.f; 
		float batCenterY = batBounds.top + batBounds.height / 2.f;
		ball->SetPosition({ batBounds.left + batBounds.width + ballRadius, batCenterY });

		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			ballActive = true;
			sf::Vector2f dir(1.f, -1.f);
			Utils::Nomalize(dir);
			ball->Fire(dir,500.f);
		}
	}
}
void SceneGame::SetGameOver()
{
	//Enter();
	SCENE_MGR.ChangeScene(SceneIds::Game);
}
