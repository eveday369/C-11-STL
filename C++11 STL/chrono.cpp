#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

void Test()
{
	for (long i = 0; i < 10000000; ++i)
	{
		sqrt(123.456L);
	}
}

int main()
{
	cout << "- 시간 단위 -" << endl;
	chrono::system_clock::time_point start = chrono::system_clock::now();
	Test();
	chrono::system_clock::time_point end = chrono::system_clock::now();
	chrono::duration<double> sec = end - start;
	chrono::nanoseconds nano = end - start;
	chrono::microseconds micro = chrono::duration_cast<chrono::microseconds>(end - start);
	chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(end - start);
	chrono::minutes minutes = chrono::duration_cast<chrono::minutes>(end - start);
	chrono::hours hour = chrono::duration_cast<chrono::hours>(end - start);

	cout << "Test() 함수를 수행하는 데 걸린 시간(초): " << sec.count() << "seconds" << endl;
	cout << "Test() 함수를 수행하는 데 걸린 시간(초): " << nano.count() << "nano sec" << endl;
	cout << "Test() 함수를 수행하는 데 걸린 시간(초): " << micro.count() << "micro sec" << endl;
	cout << "Test() 함수를 수행하는 데 걸린 시간(초): " << mill.count() << "mill sec" << endl;
	cout << "Test() 함수를 수행하는 데 걸린 시간(초): " << minutes.count() << "minutes" << endl;
	cout << "Test() 함수를 수행하는 데 걸린 시간(초): " << hour.count() << "hours" << endl;
	cout << endl << endl;

	cout << "- 시간 연산 -" << endl;
	{
		chrono::hours H1(1);
		cout << "H1(1) : " << H1.count() << endl;

		chrono::seconds S1(10);
		chrono::seconds S2(120);
		cout << "S1(10) : " << S1.count() << endl;
		cout << "S2(120) : " << S2.count() << endl;
	}

	{
		chrono::hours H1(1);
		chrono::hours H2(2);
		chrono::hours H3 = H1 + H2;
		cout << "H1 + H2 = " << H3.count() << endl;
		chrono::seconds S1(10);
		chrono::milliseconds MILS1(100);
		chrono::milliseconds MILS2 = S1 + MILS1;
		cout << "S1 + MILS1 = " << MILS2.count() << endl;
		chrono::seconds S2 = chrono::duration_cast<chrono::seconds>(S1 + MILS1);
		cout << "S1 + MILS1 = " << S2.count() << endl;
	}

	return 0;
}