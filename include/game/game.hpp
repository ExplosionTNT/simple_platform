/*
	Docs
*/

#pragma once


// Headers
#include "game/gameplay_scene.hpp"
#include <SDL2/SDL.h>


class Game {
	public:
		Game(const Game&) = delete;
		static Game& get();

		void run();

	private:
		Game();
		
		void init();
		void process_event();
		void handle_events();
		void update();
		void render();
		void frame();
		void loop();
		void destroy();
		
		static Game _instance;

		GameplayScene &gameplay_scene = GameplayScene::get();
		bool is_running;
		SDL_Event event;

};