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
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	
	ChuNhatDac(renderer, 1, 1);
	SDL_RenderPresent(renderer);
	
	SDL_Event e;
	int count = 0;
	
	while( SDL_WaitEvent(&e) ) {
		if( e.type == SDL_MOUSEBUTTONDOWN ) {
			if( e.button.button == SDL_BUTTON_LEFT ) {
				if( e.button.x < 100 && e.button.y < 100 ) {
					cout << ++count << endl;
				}
			}
		}
	}
	
	quitSDL(window, renderer);
	return 0;
}
