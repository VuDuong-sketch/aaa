#include <iostream>
#include <SDL.h>

using namespace std;


void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

void moveGame(const string& path);


int main(int argc, char* argv[]) {
	
	SDL_Event e;
	int count = 0;
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	
	while( SDL_PollEvent(&e) );
	
	while( SDL_WaitEvent(&e) ) {
		count++;
		cout << count << endl;
	}
	
	quitSDL(window, renderer);
	return 0;
}
