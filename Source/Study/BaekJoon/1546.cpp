#include <iostream>

using namespace std;

int main()
{
	int N{};
	int Max{};
	float result{};
	cin >> N;
	float* Score = new float[N];

	for (int i = 0; i < N; ++i) {
		cin >> Score[i];
		if (Score[i] > Max) {
			Max = Score[i];
		}
	}

	for (int i = 0; i < N; ++i) {
		Score[i] = (Score[i] / Max) * 100.f;
		result += Score[i];
	}

	cout << result / N << endl;

	delete[] Score;
}