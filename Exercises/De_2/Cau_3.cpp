#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool number(char c) {
	return ( 48 <= c && c <= 57 );
}

int char_to_int( char c ) {
	return int(c) - 48;
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

string deCode(string s) {
	string str;
	
	for(int i = 0; s[i] != '\0'; i++) {
		
		if( number(s[i]) ) {
			
			string num;
			for(int j = i; number(s[j]); j++) num += s[j];
			
			int n = string_to_int(num);
			char c = s[i + num.length()];
			for(int j = 1; j <= n; j++) str += c;
			i++;
			
		}
		else str += s[i];
		
	}
	return str;
}
