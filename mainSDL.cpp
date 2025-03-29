#include <iostream>
#include <SDL.h>
using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

void moveGame();

int main(int argc, char* argv[]) {
	
	moveGame();
	
	return 0;
}
