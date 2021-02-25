#include <iostream>

using namespace std;

int main()
{
	int Array[10];
	int Max{};
	int num{};
	for (int i = 0; i < 9; ++i)
		cin >> Array[i];

	for (int i = 0; i < 9; ++i) {
		if (Array[i] > Max) {
			Max = Array[i];
			num = i + 1;
		}
	}

	cout << Max << " " << num << endl;

}