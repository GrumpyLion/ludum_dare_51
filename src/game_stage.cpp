#include "game_stage.h"

void GameStage::init()
{
	world = createWorld("stages/game_world");
	auto factory = EntityFactory(*world, getResources());
	factory.createScene(getResource<Scene>("test"), true);
	auto camera = factory.createEntity("camera");
}

void GameStage::onFixedUpdate(Time t)
{
	world->step(TimeLine::FixedUpdate, t);
}

void GameStage::onVariableUpdate(Time t)
{
	world->step(TimeLine::VariableUpdate, t);
}

void GameStage::onRender(RenderContext& rc) const
{
	world->render(rc);
}
