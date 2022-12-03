/*
	Docs
*/


// Headers
#include "game/game.hpp"


// Game singleton instance
Game Game::_instance;

Game& Game::get() {
	// Game return the singleton instance
	return _instance;
}

// Game init method
Game::Game():is_running(true) {}

void Game::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameplay_scene.init();
}

void Game::process_event() {

	// process all events
	switch(this->event.type) {
		case SDL_QUIT: this->is_running = false; break;
	}
}

void Game::handle_events() {
	// get all events to process
	while (SDL_PollEvent(&this->event)) {
		this->process_event();
	}
}

void Game::update() {
	this->handle_events();
	this->gameplay_scene.update();
}

void Game::render() {
	this->gameplay_scene.render();
}

void Game::frame() {
	this->update();
	this->render();
}

void Game::loop() {
	while (this->is_running) {
		this->frame();
	}
}

void Game::destroy() {
	this->gameplay_scene.destroy();
	SDL_Quit();
}

void Game::run() {
	this->init();
	this->loop();
	this->destroy();
}