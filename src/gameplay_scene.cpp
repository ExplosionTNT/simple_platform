/*
	Docs
*/


// Headers
#include "game/gameplay_scene.hpp"


// GameplayScene singleton instance
GameplayScene GameplayScene::_instance;

GameplayScene& GameplayScene::get() {
	// GameplayScene return the singleton instance
	return _instance;
}

// GameplayScene init method
GameplayScene::GameplayScene() {}

void GameplayScene::init() {
	this->window.init();
	this->window.set_draw_color(0, 0, 0, 255);
}

void GameplayScene::destroy() {
	this->window.destroy();
}

void GameplayScene::update() {
	
}

void GameplayScene::render() {
	this->window.fill();
	this->window.update();
}