#include <iostream>
#include <SDL.h>

using namespace std;


void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

void moveGame(const string& path);

void ChuNhatDac(SDL_Renderer* renderer, int a, int b);

void Tuong(SDL_Renderer* renderer, int a, int b);

void ChuX (SDL_Renderer* renderer, int a, int b);

void Box (SDL_Renderer* renderer, int a, int b);

void Draw_Arrow (SDL_Renderer* renderer, int a, int b);

int main(int argc, char* argv[]) {
	
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	
	Draw_Arrow(renderer, 3, 6);
	
	SDL_RenderPresent(renderer);
	waitUntilPressed();
	
	quitSDL(window, renderer);
	return 0;
}
