#include <iostream> 
#include <math.h>
#include <emmintrin.h>
#include <string.h>
#include <ctype.h>

using namespace std;

bool isCorrectInputForSystem (const char inputStr [], const int base);
int getNumberForChar(const char c);
int conventorIntoTheBinarySystem(const char numInBase, const int powOfNum);

int main() {
	int num, firstPower, powOfSecondNum;
	unsigned __int64 firstNumInBinary = 0, secondNumInBinary = 0;
	unsigned __int64 j, sh, p, q;
	unsigned __int64 b = 0;	
	unsigned __int64 k = 1; 
	unsigned __int64 k1 = 0;
	char firstNum[10], secondNum[10];
    int lenFirst = strlen(firstNum);
    int lenSecond = strlen(secondNum);
	cout << "| N |    Function    |" << endl;
	cout << "----------------------" << endl;
	cout << "| 1 |    Addition    |" << endl;
	cout << "| 2 |   Subtraction  |" << endl;
	cout << "| 3 | Multiplication |" << endl;
	cout << "| 4 |    Division    |" << endl;
	cout << "| 5 |   Comparison   |" << endl;
	cout << "Enter the serial number of functions: " << endl;
	cin >> num;
	
	cout << "Enter the first number and it's power: " << endl;
	std::cin >> firstNum; cin >> firstPower;		
	firstNumInBinary = conventorIntoTheBinarySystem(firstNum, firstPower);	
	cout << "Your first number into the binary system: " << firstNumInBinary << endl;
	
	cout << "Enter the second number and it's power: " << endl;
	std::cin >> secondNum; 	cin >> powOfSecondNum; 
	cout << "Your second number into the binary system: " << conventorIntoTheBinarySystem(secondNum, powOfSecondNum) << endl;
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

int conventorIntoTheBinarySystem(const char numInBase, const int powOfNum){
	int numInBinary;
	int numInDecimal = 0;
	int p = strlen(firstNum) - 1;
	int k = 1;
	if (!isCorrectInputForSystem(numInBase, powOfNum)){
		cout << "Wrong number has been entered";
		return 0; // exit programm
	}
	for (int j = 0; numInBase[j] != '\0'; j++) {
		numInDecimal = numInDecimal + getNumberForChar(numInBase[j]) * pow(powOfNum,p);
		p--; 
	}
	while (numInDecimal != 0) {
		numInBinary = numInBinary + numInDecimal % 2 * k;
		k = k * 10;
		numInDecimal = numInDecimal / 2;
	}
	return numInBinary;
}
