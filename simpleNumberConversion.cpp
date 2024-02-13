#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string divideInBase(int base, const string& number, int divisorNumber, int* remainder) {
	string resultOfDivision = "";
	int currentRemainder = 0;
	int amountOfDigits = number.size();
	int thisDigit = 0;
	int thisDivisionResult = 0;

	for (int i = 0 ; i < amountOfDigits ; i++) {
		if (number[i] >= '0' && number[i] <= '9') {
			thisDigit = number[i] - '0';
		}
		else if (number[i] >= 'A' && number[i] <= 'Z') {
			thisDigit = number[i] - 'A' + 10;
		}

		currentRemainder = currentRemainder*base+thisDigit;
		thisDivisionResult = currentRemainder/divisorNumber;

		if ( !( (resultOfDivision == "") && thisDivisionResult == 0) ) {
			// Numbers 0-9
			if (thisDivisionResult <= 9) {
				resultOfDivision += '0' + thisDivisionResult;
			}
			// Letters A-Z
			else if (thisDivisionResult >= 10){
				resultOfDivision += 'A' + thisDivisionResult - 10;
			}
		}

		currentRemainder %= divisorNumber;
	}

	// Updating the final result of remainder
	*remainder = currentRemainder;

	// Edge-case!!! - when result==0
	if (resultOfDivision == ""){
		return "0";
	}
	else {
		return resultOfDivision;
	}
}

int main() {

	int amountOfNumbers = 0;
	cin >> amountOfNumbers;

	for (int x = 0; x < amountOfNumbers; x++) {
		string number = "";
		string result = "";
		int base1 = 0;
		int base2 = 0;
		int remainder = 0;
		char symbol = 0;

		cin >> number;
		cin >> base1;
		cin >> base2;

		while (true) {

			// Conversion base1 --> base2
			number = divideInBase(base1, number, base2, &remainder);

			// Info - dziele liczbe w systemie o danej podstawie i zapisuje reszty - dzieki temu nie musze przechodzic
			// posrednio przez system o podstawie 10. Wskazowki matematyczne jak to zrobic znalazlem na ponizszej stronie:
			// https://math.stackexchange.com/questions/1443885/converting-a-number-from-one-base-to-another-without-going-through-base-10

			symbol = remainder;

			// Changing int to char
			if (remainder >= 0 && symbol <= 9) {
				symbol += '0';
			}
			else {
				symbol += 'A' - 10;
			}

			result = symbol + result;
			if (number == "0") {
				break;
			}
		}
		cout << result << endl;
	}

	return 0;
}