#include <iostream>

using namespace std;


int main()
{
	char Input[80]{};

	int Score{};
	int Sum{};
	int Time{};
	int TestCase{};
	cin >> TestCase;

	
	while (Time < TestCase) {
		cin >> Input;

		for (int i = 0; i < strlen(Input); ++i) {
			if (Input[i] == 'O') {
				Score++;
				Sum += Score;
			}
			else{
				Score = 0;
			}
		}

		cout << ": " << Sum << endl;
	}

}