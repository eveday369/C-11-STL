#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main()
{
	cout << "- ������ ���� ���� -" << endl;
	{
		mt19937 mtRand;

		for (int i = 0; i < 7; ++i)
		{
			cout << mtRand() << endl;
		}
	}
	cout << endl << endl;

	cout << "- ���� �ð��� �õ� ������ ���� ���� -" << endl;
	{
		auto curTime = chrono::system_clock::now();
		auto duration = curTime.time_since_epoch();
		auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();

		mt19937 mtRand(millis);

		for (int i = 0; i < 7; ++i)
		{
			cout << mtRand() << endl;
		}
	}
	cout << endl << endl;

	cout << "- ������� ���� ���� -" << endl;
	{
		random_device rng;

		for (int i = 0; i < 7; ++i)
		{
			auto result = rng();
			cout << result << endl;
		}
	}
	cout << endl << endl;

	cout << "- ���� ���� ���� ���� ���� -" << endl;
	{
		// -3 ~ 3 ������ ���� ����
		mt19937_64 rng1(3244);
		uniform_int_distribution<long long> dist1(-3, 3);

		cout << "dist1�� �ּ� �� : " << dist1.min() << endl;
		cout << "dist1�� �ִ� �� : " << dist1.max() << endl;

		for (int i = 0; i < 7; ++i)
		{
			cout << dist1(rng1) << endl;
		}
		cout << endl;

		mt19937 rng2;
		uniform_real_distribution<double>dist2(0.0, 1.0);

		for (int i = 0; i < 7; ++i)
		{
			cout << dist2(rng2) << endl;
		}
	}
	cout << endl << endl;

	cout << "- 70% Ȯ���� ���� ���� -" << endl;
	{
		mt19937_64 rng1(3244);

		bernoulli_distribution dist(0.7);

		int nSuccess = 0;
		int nFail = 0;

		for (int i = 0; i < 100; ++i)
		{
			bool result = dist(rng1);

			if (result)
				++nSuccess;
			else
				++nFail;
		}
		cout << "���� Ƚ�� : " << nSuccess << ", ���� Ƚ�� : " << nFail << endl;
	}
	cout << endl << endl;

	cout << "- 30% Ȯ���� 1000�� �õ����� �� ���� Ƚ�� -" << endl;
	{
		mt19937_64 rng1(3244);
		binomial_distribution<> dist(1000, 0.3);

		int result = dist(rng1);
		cout << result << endl;
	}
	cout << endl << endl;

	cout << "- ���� ����(��� 173, ǥ������ 5) -" << endl;
	{
		mt19937_64 rng1(3244);

		normal_distribution<> dist(173, 5);

		for (int i = 0; i < 10; ++i)
		{
			int result = dist(rng1);
			cout << result << endl;
		}
	}


	return 0;
}