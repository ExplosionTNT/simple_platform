/*
	Docs
*/

#pragma once


// Headers
#include "game/window.hpp"
#include <SDL2/SDL.h>


class GameplayScene {
	public:
		GameplayScene(const GameplayScene&) = delete;
		static GameplayScene& get();

		void init();
		void destroy();

		void update();
		void render();

	private:
		GameplayScene();
		static GameplayScene _instance;

		Window &window = Window::get();
};