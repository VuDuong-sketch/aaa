#include <iostream>
#include <SDL.h>
using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

char a[100][100];
int m, n;
SDL_Event e;
bool flag;

struct coordinates {
	int x, y;
	coordinates(int b, int a) {
		x = a;
		y = b;
	}
};

coordinates M(1,1), B(2,2);

void printArr() {
	for(int i = 0; i < m + 2; i++) {
		for(int j = 0; j < n + 2; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Move() {
	if( e.key.keysym.sym == SDLK_UP ) {
		if( a[M.y - 1][M.x] == char(219) ) {
			return;
		}
		
		if( a[M.y - 1][M.x] == char(98) ) {
			if( a[M.y - 2][M.x] == char(219) || a[M.y - 2][M.x] == char(98) ) {
				return;
			}
			a[M.y][M.x] = ' ';
			a[M.y - 2][M.x] = 98;
			a[M.y - 1][M.x] = 15;
			B.y--;
			M.y--;
			return;
		}
		
		a[M.y][M.x] = ' ';
		a[M.y - 1][M.x] = 15;
		M.y--;
		return;
	}
	if( e.key.keysym.sym == SDLK_LEFT ) {
		if( a[M.y][M.x - 1] == char(219) ) {
			return;
		}
		
		if( a[M.y][M.x - 1] == char(98) ) {
			if( a[M.y][M.x - 2] == char(219) || a[M.y][M.x - 2] == char(98) ) {
				return;
			}
			a[M.y][M.x] = ' ';
			a[M.y][M.x - 2] = 98;
			a[M.y][M.x - 1] = 15;
			B.x--;
			M.x--;
			return;
		}
		
		a[M.y][M.x] = ' ';
		a[M.y][M.x - 1] = 15;
		M.x--;
		return;
	}
	if( e.key.keysym.sym == SDLK_DOWN ) {
		if( a[M.y + 1][M.x] == char(219) ) {
			return;
		}
		
		if( a[M.y + 1][M.x] == char(98) ) {
			if( a[M.y + 2][M.x] == char(219) || a[M.y + 2][M.x] == char(98) ) {
				return;
			}
			a[M.y][M.x] = ' ';
			a[M.y + 2][M.x] = 98;
			a[M.y + 1][M.x] = 15;
			B.y++;
			M.y++;
			return;
		}
		
		a[M.y][M.x] = ' ';
		a[M.y + 1][M.x] = 15;
		M.y++;
		return;
	}
	if( e.key.keysym.sym == SDLK_RIGHT ) {
		if( a[M.y][M.x + 1] == char(219) ) {
			return;
		}
		
		if( a[M.y][M.x + 1] == char(98) ) {
			if( a[M.y][M.x + 2] == char(219)  || a[M.y][M.x + 2] == char(98)) {
				return;
			}
			a[M.y][M.x] = ' ';
			a[M.y][M.x + 2] = 98;
			a[M.y][M.x + 1] = 15;
			B.x++;
			M.x++;
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

void moveGame() {
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	
	m = 60;
	n = 80;
	
	for(int i = 0; i < m + 2; i++) {
		for(int j = 0; j < n + 2; j++) {
			if(i == 0 || i == m + 1 || j == 0 || j == n + 1) a[i][j] = 219;
			else a[i][j] = ' ';
		}
	}
	a[1][1] = 15;
	a[2][2] = 98;
	a[3][3] = 98;
	//printArr();
	while(SDL_WaitEvent(&e)) {
		
		if( e.type == SDL_KEYDOWN ) {
			Move();
		}
		if( e.type == SDL_QUIT ){
			cout << "Game Over !" << endl;
			return;
		}
		//printArr();
		//draw and present
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if( a[i][j] == char(15) ) {
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
					ChuNhatDac(renderer, (j - 1) * 10, (i - 1) * 10, j * 10 - 1, i * 10 - 1);
				}
				if( a[i][j] == char(98) ) {
					SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
					ChuNhatDac(renderer, (j - 1) * 10, (i - 1) * 10, j * 10 - 1, i * 10 - 1);
				}
			}
		}
		 		
		SDL_RenderPresent(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if( a[i][j] != ' ' ) {
					ChuNhatDac(renderer, (j - 1) * 10, (i - 1) * 10, j * 10 - 1, i * 10 - 1);
				}
			}
		}
	}
	quitSDL(window, renderer);
	return;
}
