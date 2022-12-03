/*
	Docs
*/

#pragma once


// Headers
#include <SDL2/SDL.h>
#include <iostream>


class Window {
	public:
		Window(const Window&) = delete;
		static Window& get();

		void init();
		void destroy();

		void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void fill();

		void update();

	private:
		Window();
		static Window _instance;

		void exit_by_init_error(const char *error);
		void create_sdl_window();
		void destroy_sdl_window();
		void create_sdl_renderer();
		void destroy_sdl_renderer();

		SDL_Window *sdl_window;
		SDL_Renderer *sdl_renderer;
};