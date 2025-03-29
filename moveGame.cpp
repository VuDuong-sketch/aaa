#include <iostream>
#include <SDL.h>
using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

char a[30][30];
int m, n;
SDL_Event e;
bool flag;

struct coordinates{
	int x, y;
	coordinates(int b, int a){
		x = a;
		y = b;
	}
};

coordinates M(1,1);

void printArr(){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Move(){
	if(e.key.keysym.sym == SDLK_UP){
		if(a[M.y - 1][M.x] == char(219)){
			flag = 1;
			return;
		}
		a[M.y][M.x] = ' ';
		a[M.y - 1][M.x] = 15;
		M.y--;
		return;
	}
	if(e.key.keysym.sym == SDLK_LEFT){
		if(a[M.y][M.x - 1] == char(219)){
			flag = 1;
			return;
		}
		a[M.y][M.x] = ' ';
		a[M.y][M.x - 1] = 15;
		M.x--;
		return;
	}
	if(e.key.keysym.sym == SDLK_DOWN){
		if(a[M.y + 1][M.x] == char(219)){
			flag = 1;
			return;
		}
		a[M.y][M.x] = ' ';
		a[M.y + 1][M.x] = 15;
		M.y++;
		return;
	}
	if(e.key.keysym.sym == SDLK_RIGHT){
		if(a[M.y][M.x + 1] == char(219)){
			flag = 1;
			return;
		}
		a[M.y][M.x] = ' ';
		a[M.y][M.x + 1] = 15;
		M.x++;
		return;
	}
}

void ChuNhatDac(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) {
	for(int i = x1; i <= x2; i++) {
		for(int j = y1; j <= y2; j++) {
			SDL_RenderDrawPoint(renderer, i, j);
		}
	}
}

void XoaChuNhatDac(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) {
	for(int i = x1; i <= x2; i++) {
		for(int j = y1; j <= y2; j++) {
			SDL_RenderDrawPoint(renderer, i, j);
		}
	}
}

void moveGame(){
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	
	
	cin >> m >> n;
	m += 2;
	n += 2;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i == 0 || i == m - 1 || j == 0 || j == n - 1) a[i][j] = 219;
			else a[i][j] = ' ';
		}
	}
	a[1][1] = 15;
	printArr();
	while(SDL_WaitEvent(&e)) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		XoaChuNhatDac(renderer, (M.x - 1) * 100, (M.y - 1) * 100, M.x * 100, M.y * 100);
		if(e.type == SDL_KEYDOWN) {
			Move();
		}
		if(flag){
			cout << "Game Over !" << endl;
			return;
		}
		printArr();
		//draw and present
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		ChuNhatDac(renderer, (M.x - 1) * 100, (M.y - 1) * 100, M.x * 100, M.y * 100);
		SDL_RenderPresent(renderer);

		
	}
	quitSDL(window, renderer);
	return;
}
