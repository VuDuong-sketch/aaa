#include <iostream>
#include <SDL.h>
#include <fstream>
#include <SDL_ttf.h>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!";
const int K = 100;

char current[8][10];
int m = 6, n = 8;
SDL_Event e;

int char_to_int( char c ) {
	return int(c) - 48;
}

char int_to_char( int n ) {
	return char(n + 48);
}

int string_to_int (string s) {
    int sm = 0, sc;
    
    for(int i = ( s[0] == '-' ? 1 : 0 ); s[i] != '\0'; i++) {
        sc = char_to_int(s[i]);
        sm = sm * 10 + sc;
    }
    if( s[0] == '-' ) sm *= -1;
    return sm;
}

string reverse(string& s) {
	int len = s.length();
	for(int i = 0; i < len / 2; i++) {
		swap(s[i], s[len - 1 - i]);
	}
	return s;
}

string int_to_string(int n) {
	string s;
	bool flag = false;
	if( n == 0 ) return "0";
	if( n < 0 ) {
		flag = true;
		n *= -1;
	}
	while( n != 0 ) {
		s += int_to_char(n % 10);
		n /= 10;
	}
	if( flag ) s += '-';
	reverse(s);
	return s;
}

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
	while( SDL_WaitEvent(&e) ) {
		if( e.type == SDL_KEYDOWN || e.type == SDL_QUIT || e.type == SDL_MOUSEBUTTONDOWN ) return;
	}
}

void Draw_Filled_Square (SDL_Renderer* renderer, int i, int j) {
	
	int x1 = (j - 1) * K,
		y1 = (i - 1) * K,
		x2 = j * K - 1,
		y2 = i * K - 1;
	
	
	for(int y = y1; y <= y2; y++) {
		for(int x = x1; x <= x2; x++) {
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}

char* string_to_CharPointer (const string& s) {
	char* ptr = new char[s.length() + 1];
	for(int i = 0; s[i] != '\0'; i++) {
		ptr[i] = s[i];
	}
	ptr[s.length()] = '\0';
	return ptr;
}

void get_text_and_rect (SDL_Renderer* renderer, int x, int y, string str_text, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect, int red, int green, int blue) {
	
	char* text = string_to_CharPointer(str_text);
	
	
    int text_width;
    int text_height;
    SDL_Surface* surface;
    SDL_Color textColor = {red, green, blue, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
    
    delete[] text;
}

void Draw_Number (SDL_Renderer* renderer, int i, int j, int n) {
	SDL_Texture* texture;
    SDL_Rect rect;
    
    TTF_Init();
    
    int x, y;
    
    
    TTF_Font* font = TTF_OpenFont("walgreensscriptfreeversion.ttf", 60);
    
    if( n < 10 ) {
    	x = (j - 1) * K + 34,
		y = (i - 1) * K + 24;
	}
	else {
		x = (j - 1) * K + 17,
		y = (i - 1) * K + 24;
	}
    
    get_text_and_rect(renderer, x, y, int_to_string(n), font, &texture, &rect, 255, 255, 255);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    Draw_Filled_Square(renderer, i, j);
    
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

int convert(int x) {
	return x / K + 1;
}

int main(int argc, char** argv) {
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	initSDL(window, renderer);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 8; j++) {
			Draw_Number(renderer, i, j, 10 * i + j);
		}
	}
	SDL_RenderPresent(renderer);
	
	ofstream outfile("C:/Users/Administrator/test.txt");
	
	while( SDL_WaitEvent(&e) ) {
		
		
		
		
		if( e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT ) {
			
			outfile << convert(e.button.y) << ' ' << convert(e.button.x) << ' ' << 120 << endl;
		}
	}
	
	return 0;
}














