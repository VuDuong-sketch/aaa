#include <iostream>
#include <SDL.h>

using namespace std;


void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

void moveGame(const string& path);


int main(int argc, char* argv[]) {
	
	string path, level;
	bool flag;
	
	do {
		path = "E:/Sketch/map/level";
		cout << "Chon man: ";
		cin >> level;
		path += level;
		path += ".txt";
		moveGame(path);
		cout << "Ban co muon choi tiep? (1 or 0) : ";
		cin >> flag;
	} while( flag );
	
	return 0;
}
