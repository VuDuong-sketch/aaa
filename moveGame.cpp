#include <iostream>
#include <SDL.h>
#include <cmath>
using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilPressed();

char a[100][100], x[100][100];
int m, n;
SDL_Event e;
bool flag;
const int K = 100;

struct coordinates {
	int x, y;
	coordinates(int b, int a) {
		x = a;
		y = b;
	}
};

coordinates M(1,1);

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
			
			M.x++;
			return;
		}
		
		a[M.y][M.x] = ' ';
		a[M.y][M.x + 1] = 15;
		M.x++;
		return;
	}
}

void ChuNhatDac(SDL_Renderer* renderer, int a, int b) {
	
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
	
	
	for(int i = x1; i <= x2; i++) {
		for(int j = y1; j <= y2; j++) {
			SDL_RenderDrawPoint(renderer, i, j);
		}
	}
}

void ChuX (SDL_Renderer* renderer, int a, int b) {
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
		
	for(int i = y1, j = x1; i <= y2; i++, j++) {
		SDL_RenderDrawPoint(renderer, i, j);
	}
	for(int i = y1, j = x2; i <= y2; i++, j--) {
		SDL_RenderDrawPoint(renderer, i, j);
	}	
}

void moveGame() {
	
	m = 600 / K;
	n = 800 / K;
	//xay map
	for(int i = 0; i < m + 2; i++) {
		for(int j = 0; j < n + 2; j++) {
			if(i == 0 || i == m + 1 || j == 0 || j == n + 1) a[i][j] = 219;
			else a[i][j] = ' ';
		}
	}
	
	while(true) {
		int i, j, c;
		cin >> i >> j >> c;
		if( c == -1 ) break;
		if( c == 120 ) {
			x[i][j] = c;
			continue;
		}
		if( c == 15 ) {
			a[i][j] = c;
			M.y = i;
			M.x = j;
		}
		a[i][j] = c;
	}
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	
	
	
	//printArr();
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if( a[i][j] == char(15) ) {
				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
				ChuNhatDac(renderer, j, i);
			}
			if( a[i][j] == char(98) ) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
				ChuNhatDac(renderer, j, i);
			}
			if( a[i][j] == char(219) ) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				ChuNhatDac(renderer, j, i);
			}
			if( x[i][j] == char(120) ) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
				ChuX(renderer, j, i);
			}
		}
	}
	SDL_RenderPresent(renderer);
	
	while( SDL_WaitEvent(&e) ) {
		
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
					ChuNhatDac(renderer, j, i);
				}
				if( a[i][j] == char(98) ) {
					SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
					ChuNhatDac(renderer, j, i);
				}
				if( x[i][j] == 'x' ) {
					SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
					ChuX(renderer, j, i);
				}
			}
		}
		 		
		SDL_RenderPresent(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if( a[i][j] != ' ' && a[i][j] != char(219) ) {
					ChuNhatDac(renderer, j, i);
					if(x[i][j] == 'x') {
						SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
						ChuX(renderer, j, i);
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
					}
				}
			}
		}
	}
	quitSDL(window, renderer);
	return;
}
