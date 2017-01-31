#include <iostream> 
#include <math.h>
#include <emmintrin.h>
#include <string.h>
#include <ctype.h>

using namespace std;

bool isCorrectInputForSystem (const char inputStr [], const int base);
int getNumberForChar(const char c);
unsigned __int64 conventorIntoTheBinarySystem(const char numInBase[], const int powOfNum);
unsigned __int64 firstOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary);
unsigned __int64 secondOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary);
unsigned __int64 thirdOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary);
unsigned __int64 forthOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary);
char* fifthOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary);

int main() {
	int num, firstPower, secondPower;
	unsigned __int64 firstNumInBinary, secondNumInBinary;
	unsigned __int64 multiplicationInBinary, additionInBinary, subtractionInBinary, divisionInBinary;
	unsigned __int64 j, sh, p, q;
	unsigned __int64 b = 0;	
	unsigned __int64 k = 1; 
	unsigned __int64 k1 = 0;
	char firstNum[10], secondNum[10];
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
	std::cin >> secondNum; 	cin >> secondPower;
	secondNumInBinary = conventorIntoTheBinarySystem(secondNum, secondPower); 
	cout << "Your second number into the binary system: " << secondNumInBinary << endl;
	
	if (num == 1) {
		additionInBinary = firstOperation(firstNumInBinary, secondNumInBinary);
		cout << additionInBinary << endl;
	}
	
	if (num == 2){
		subtractionInBinary = secondOperation(firstNumInBinary, secondNumInBinary);
		cout << subtractionInBinary << endl;
	}
	
	if (num == 3) {
		multiplicationInBinary = thirdOperation(firstNumInBinary, secondNumInBinary);
		cout << multiplicationInBinary << endl;
	}
	
	if (num == 4) {
		unsigned __int64 j = 0;
		unsigned __int64 division = firstNumInBinary, trialDivision = 0;
		while (division >= secondNumInBinary){
			trialDivision = firstNumInBinary - secondNumInBinary;
			cout << "trd" << trialDivision << endl;
			int k = 0;
			division = trialDivision;
				for(k = 0; trialDivision > 0; k++){
					if ((trialDivision % 10) % 2 == 1){
						division = division - (trialDivision % 10 - 1) * pow(10, k);
					} 
					if ((trialDivision % 10) % 2 == 0){
						division = division - (trialDivision % 10) * pow(10, k); 
					}
					trialDivision = division / pow(10, k + 1);
					cout << "div" << division << endl;
				}	
				j++;
				
			}
			cout << j;
		}

	if (num == 5){
		cout << firstNumInBinary <<" " << fifthOperation(firstNumInBinary, secondNumInBinary) << " " << secondNumInBinary;
	}
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

unsigned __int64 conventorIntoTheBinarySystem(const char numInBase[], const int powOfNum){
	unsigned __int64 numInBinary = 0;
	int numInDecimal = 0;
	int p = strlen(numInBase) - 1;
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

unsigned __int64 firstOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary){
	unsigned __int64 addition = 0, trialAddition = 0;
		trialAddition = firstInBinary + secondInBinary;
		int k = 0;
		addition = trialAddition;
		while (trialAddition > 0){
			if (trialAddition % 10 == 2){
				addition = addition - (trialAddition % 10) * pow(10, k) + pow(10, k + 1);
			} else if (trialAddition % 10 == 3){
				addition = addition - (trialAddition % 10 - 1) * pow(10, k) + pow(10, k + 1); 
			} else if (trialAddition % 10 == 4){
				addition = addition - (trialAddition % 10) * pow(10, k) + pow(10, k + 1);
			}
			trialAddition = addition / pow(10, k + 1);
			k++;
		}
	return addition;
	
}

unsigned __int64 secondOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary){
	unsigned __int64 subtraction = 0, trialSubtraction = 0;
		trialSubtraction = firstInBinary - secondInBinary;
		int k = 0;
		subtraction = trialSubtraction;
		while (trialSubtraction > 0){
			if (trialSubtraction % 10 == 9){
				subtraction = subtraction - (trialSubtraction % 10 - 1) * pow(10, k);
			} 
			else if (trialSubtraction % 10 == 8){
				subtraction = subtraction - (trialSubtraction % 10) * pow(10, k); 
			}
			trialSubtraction = subtraction / pow(10, k + 1);
			k++;
	}
	return subtraction;
}

unsigned __int64 thirdOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary){
	unsigned __int64 multiplication = 0, x = 0, y = 0;
	int cnt;
	for (cnt = 0; secondInBinary > 0; secondInBinary /= 10) {
		multiplication += firstInBinary * (secondInBinary % 10)*pow(10, cnt);
		cnt++;
	}
	if (firstInBinary > 0 || secondInBinary > 0) {
		for (cnt = 0; cnt++, firstInBinary = multiplication / pow(10, cnt);) {
			x = (firstInBinary % 10);
			if (x > 1) {
				y = x % 2;
				if (y == 0) {
					multiplication -= x*pow(10, cnt);
					multiplication += (x / 2)*pow(10, cnt + 1);
				} else {
					multiplication -= (x*pow(10, cnt) - (pow(10, cnt)));
					multiplication += ((x - 1) / 2)*pow(10, cnt + 1);
				}
			}
		}
	}
	return multiplication;
}

unsigned __int64 forthOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary){
	unsigned __int64 j = 0;
	unsigned __int64 division = 0, trialDivision = firstInBinary;
	while (trialDivision >= secondInBinary){
		trialDivision = firstInBinary - secondInBinary;
		int k = 0;
		division = trialDivision;
		while (trialDivision > 0){
			if (trialDivision % 10 == 9){
				division = division - (trialDivision % 10 - 1) * pow(10, k);
			} 
			else if (trialDivision % 10 == 8){
				division = division - (trialDivision % 10) * pow(10, k); 
			}
			trialDivision = division / pow(10, k + 1);
			k++;
			cout << division << endl;
		}	
		j++;
		cout << j;
	}
	return j;
}

char* fifthOperation (unsigned __int64 firstInBinary, unsigned __int64 secondInBinary){
	char* comparisonSign;
	if (firstInBinary > secondInBinary) {
		comparisonSign = "more than";
	} else if (firstInBinary < secondInBinary) {
		comparisonSign = "less than";
	} else {
		comparisonSign = "equal to";
	}
	return comparisonSign;
}
