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


int main(int argc, char* argv[]) {
	
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	
	Tuong(renderer, 1, 1);
	
	ChuX(renderer, 3, 3);
	
	SDL_RenderPresent(renderer);
	
	waitUntilPressed();
	
	quitSDL(window, renderer);
	return 0;
}
