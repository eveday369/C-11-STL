#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main()
{
	cout << "- 간단한 난수 생성 -" << endl;
	{
		mt19937 mtRand;

		for (int i = 0; i < 7; ++i)
		{
			cout << mtRand() << endl;
		}
	}
	cout << endl << endl;

	cout << "- 현재 시간을 시드 값으로 난수 생성 -" << endl;
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

	cout << "- 비결정적 난수 생성 -" << endl;
	{
		random_device rng;

		for (int i = 0; i < 7; ++i)
		{
			auto result = rng();
			cout << result << endl;
		}
	}
	cout << endl << endl;

	cout << "- 일정 범위 안의 난수 생성 -" << endl;
	{
		// -3 ~ 3 사이의 난수 생성
		mt19937_64 rng1(3244);
		uniform_int_distribution<long long> dist1(-3, 3);

		cout << "dist1의 최소 값 : " << dist1.min() << endl;
		cout << "dist1의 최대 값 : " << dist1.max() << endl;

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

	cout << "- 70% 확률로 난수 생성 -" << endl;
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
		cout << "성공 횟수 : " << nSuccess << ", 실패 횟수 : " << nFail << endl;
	}
	cout << endl << endl;

	cout << "- 30% 확률로 1000번 시도했을 때 성공 횟수 -" << endl;
	{
		mt19937_64 rng1(3244);
		binomial_distribution<> dist(1000, 0.3);

		int result = dist(rng1);
		cout << result << endl;
	}
	cout << endl << endl;

	cout << "- 정규 분포(평균 173, 표준편차 5) -" << endl;
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