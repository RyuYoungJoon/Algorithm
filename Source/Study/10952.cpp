#include <iostream>

using namespace std;

int main()
{
	int X{};
	int Y{};

	while (true) {
		cin >> X >> Y;
		if (X == 0 && Y == 0)
			break;
		cout << X + Y << endl;

		
	}
}