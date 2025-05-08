#include <iostream>
#include <SDL.h>
#include <cmath>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!";

const int K = 100;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer) {
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilPressed() {
	SDL_Event e;
	while(true){
		if(SDL_WaitEvent(&e) != 0 && 
		(e.type == SDL_KEYDOWN || e.type == SDL_QUIT)) return;
	}
}



void ChuNhatDac(SDL_Renderer* renderer, int a, int b) {
	
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
	
	
	for(int i = y1; i <= y2; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
}

void Tuong(SDL_Renderer* renderer, int a, int b) {
	
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
	
	
	for(int i = y1; i <= y1 + 20; i++) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1; j <= x1 + 3; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 4; j <= x1 + 49; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 50; j <= x1 + 53; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 54; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = y1 + 21; i <= y1 + 24; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	for(int i = y1 + 25; i <= y1 + 45; i++) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1; j <= x1 + 24; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 25; j <= x1 + 28; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 29; j <= x1 + 74; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 75; j <= x1 + 78; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 79; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = y1 + 46; i <= y1 + 49; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	for(int i = y1 + 50; i <= y1 + 70; i++) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1; j <= x1 + 3; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 4; j <= x1 + 49; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 50; j <= x1 + 53; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 54; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = y1 + 71; i <= y1 + 74; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	for(int i = y1 + 75; i <= y1 + 95; i++) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1; j <= x1 + 24; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 25; j <= x1 + 28; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 29; j <= x1 + 74; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		for(int j = x1 + 75; j <= x1 + 78; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		for(int j = x1 + 79; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i = y1 + 96; i <= y1 + 99; i++) {
		for(int j = x1; j <= x2; j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
}

void ChuX (SDL_Renderer* renderer, int a, int b) {
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
	
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	for(int k = 0; k <= 10; k++) {
		for(int i = y1 + 10 - k, j = x1 + k; j <= x2 - 10 + k; i++, j++) {
			SDL_RenderDrawPoint(renderer, j, i);
		}
	}
	
	for(int k = 0; k <= 10; k++) {
		for(int i = y1 + 10 - k, j = x2 - k; j >= x1 + 10 - k; i++, j--) {
			SDL_RenderDrawPoint(renderer, j, i);		
		}
	}
}

void Box (SDL_Renderer* renderer, int a, int b) {
	int x1 = (a - 1) * K,
		y1 = (b - 1) * K,
		x2 = a * K - 1,
		y2 = b * K - 1;
		
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	ChuNhatDac(renderer, a, b);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int i = y1, j = x1 - k; j <= x2; i++, j++) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
		else {
			for(int i = y1 + k, j = x1;  i <= y2; i++, j++) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
	}
	
	for(int k = -10; k <= 10; k++) {
		if(k < 0) {
			for(int i = y1 - k, j = x2; i <= y2; i++, j--) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
		else {
			for(int i = y1, j = x2 - k; j >= x1; i++, j--) {
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
	}
}

int coor_convert_x ( int x ,int j ) {
	
	return K * (j - 1) + x - 1;
	
}

int coor_convert_y ( int y ,int i ) {
	
	return K * (i - 1) + y - 1;
	
}

void DrawPoint (SDL_Renderer* renderer, int x, int y, int i, int j) {
	SDL_RenderDrawPoint(renderer, coor_convert_x(x, j), coor_convert_y(y, i));
}

void Draw_Arrow (SDL_Renderer* renderer, int i, int j) {
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
	
	for(int y = 1; y <= 50; y++) {
		for(int x = 1; x <= 50; x++) {
			if( x + y >= 76 ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	for(int y = 51; y <= 100; y++) {
		for(int x = 1; x <= 50; x++) {
			if( y - x <= 25 ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	for(int y = 38; y <= 63; y++) {
		for(int x = 51; x <= 75; x++) {
			DrawPoint(renderer, x, y, i, j);
		}
	}
	
}

bool left_horn(int x, int y) {
	return ( y <= 3 * x - 50 && y >= x - 10 && y <= -x + 50 );
}

bool right_horn(int x, int y) {
	return ( y >= -x + 90 && y <= x - 50 && y <= -3 * x + 250 );
}

bool left_eye(int x, int y) {
	return ( 2 * y >= x + 45 && x >= 35 && 2 * y <= -x + 135 );
}

bool right_eye(int x, int y) {
	return ( 2 * y <= x + 35 && x <= 65 && 2 * y >= -x + 145 );
}

void Draw_Test (SDL_Renderer* renderer, int i, int j) {
	
	SDL_SetRenderDrawColor(renderer, 127, 0, 255, 0);
	
	for(int y = 1; y <= 100; y++) {
		for(int x = 1; x <= 100; x++) {
			if( pow(double(x) - 50.5, 2) + pow(double(y) - 50.5, 2) <= 30 * 30 ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	
	for(int y = 10; y <= 25; y++) {
		for(int x = 20; x <= 30; x++) {
			if( left_horn(x, y) ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	
	for(int y = 10; y <= 25; y++) {
		for(int x = 70; x <= 80; x++) {
			if( right_horn(x, y) ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int y = 40; y <= 50; y++) {
		for(int x = 35; x <= 45; x++) {
			if( left_eye(x, y) ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	
	for(int y = 40; y <= 50; y++) {
		for(int x = 55; x <= 65; x++) {
			if( right_eye(x, y) ) {
				DrawPoint(renderer, x, y, i, j);
			}
		}
	}
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	DrawPoint(renderer, 38, 45, i, j);
	DrawPoint(renderer, 38 + 1, 45, i, j);
	DrawPoint(renderer, 38 - 1, 45, i, j);
	DrawPoint(renderer, 38, 45 + 1, i, j);
	DrawPoint(renderer, 38, 45 - 1, i, j);
	
	DrawPoint(renderer, 62, 45, i, j);
	DrawPoint(renderer, 62 + 1, 45, i, j);
	DrawPoint(renderer, 62 - 1, 45, i, j);
	DrawPoint(renderer, 62, 45 + 1, i, j);
	DrawPoint(renderer, 62, 45 - 1, i, j);
	
	
}








