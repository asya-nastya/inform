#include <iostream> 
#include <math.h>
#include <emmintrin.h>
#include <string.h>
#include <ctype.h>

using namespace std; 

bool isCorrectInputForSystem (const char inputStr [], const int base);
int getNumberForChar(const char c);

int main () {	
	unsigned __int64 j, sh, p;
	unsigned __int64 b = 0;	
	unsigned __int64 k = 1; 
	unsigned __int64 k1 = 0;
	char s[10];
    int i, c;
    int len = strlen(s);
	cout << "Enter the power of number:" << endl;
    cin >> i;
    cout << "Enter the necessary power:" << endl;
    cin >> c;
    cout << "Enter the number:" << endl;
   	std::cin >> s;
   	sh=0;
   	p=strlen(s)-1;
    if (!isCorrectInputForSystem(s, i)){
   		cout << "Wrong number has been entered";
   		return 0; // exit programm
	}
   	for (j=0; s[j] != '\0'; j++) {
    	sh = sh + getNumberForChar(s[j]) * pow(i,p);
       	p--; 
	}
	if (c == i) {
		cout << "Your number is: " << s;
	} else if (c == 2) {
    	while (sh != 0) {
			b = b + sh % 2 * k;
			k = k * 10;
			sh = sh / 2;
		}
	} else if (c == 10) {
		cout << sh;		
	} else if (c != 2 && c != 10 ) {
		while (sh >= 1) {
			b = b  +  sh % c * k;
			k = k * 10;
			sh = sh / c;
		}
		return 0;
	}
	cout <<"Your new number: "<< b << endl;
}

int getNumberForChar(const char c){
	int n = -1;
	if (c >= '0' && c <= '9'){
       	n = c - 48;
	} else if (c >= 'A' && c <= 'Z'){
       	n = c - 55;
    } else if (c >= 'a' && c <= 'z'){
       	n = c - 87;
   	}
   	return n;
}

bool isCorrectInputForSystem (const char inputStr[], const int base){
	int k = 0;
	for(int j = 0; inputStr[j] != '\0'; j++){
		k = base - getNumberForChar(inputStr[j]);	 
		if (k < 1 || k > base){
			return false;
		}
	}
	return true;
}
   
