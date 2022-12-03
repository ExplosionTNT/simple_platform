/*
	Docs
*/


//Headers
#include "game/window.hpp"


// Window singleton instance
Window Window::_instance;

Window& Window::get() {
	// Window return the singleton instance
	return _instance;
}

// Window init method
Window::Window():sdl_window(NULL), sdl_renderer(NULL) {}

void Window::exit_by_init_error(const char *error) {
	SDL_Quit();

	// for debug
	std::cout << "[ERROR]: " << &error;
	system("pause");

	// exit with exit code 0
	exit(0);
}

void Window::create_sdl_window() {
	this->sdl_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920/2, 1080/2,  SDL_WINDOW_SHOWN);
	
	// check if the window was builded
	if (this->sdl_window != NULL)
		return;

	this->exit_by_init_error("SDL_CreateWindow");
}

void Window::destroy_sdl_window() {
	SDL_DestroyWindow(this->sdl_window);
}

void Window::create_sdl_renderer() {
	this->sdl_renderer = SDL_CreateRenderer(this->sdl_window, -1, 0);

	// check if the renderer was builded
	if (this->sdl_renderer)
		return;

	this->destroy_sdl_window();
	this->exit_by_init_error("SDL_CreateRenderer");
}

void Window::destroy_sdl_renderer() {
	SDL_DestroyRenderer(this->sdl_renderer);
}

void Window::init() {
	this->create_sdl_window();
	this->create_sdl_renderer();
}

void Window::destroy() {
	this->destroy_sdl_renderer();
	this->destroy_sdl_window();
	SDL_Quit();
}

void Window::set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_SetRenderDrawColor(this->sdl_renderer, r, g, b, a);
}

void Window::fill() {
	SDL_RenderClear(this->sdl_renderer);
}

void Window::update() {
	SDL_RenderPresent(this->sdl_renderer);
}