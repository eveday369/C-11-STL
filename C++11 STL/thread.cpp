#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

thread_local int nCount = 0;
mutex mtx_lock;

void Test1()
{
	cout << "Test" << endl;
}

void Test2()
{
	for (int i = 0; i < 10; ++i)
	{
		++nCount;
	}

	lock_guard<mutex> guard(mtx_lock);
	cout << "Thread ID : " << this_thread::get_id() << " nCount : " << nCount << endl;
}

int main()
{
	cout << "- 스레드 만들기 -" << endl;
	{
		thread Thread1([]()
		{
			for (int i = 0; i < 5; ++i)
			{
				cout << "Thread1 Num : " << i << endl;
			}
		});

		Thread1.join();

		thread Thread2;
		Thread2 = thread([]()
		{
			for (int i = 10; i < 15; ++i)
			{
				cout << "Thread2 Num : " << i << endl;
			}
		});

		Thread2.join();

		thread Thread3 = thread([](int nParam)
		{
			for (int i = 20; i < 25; ++i)
			{
				cout << "Thread3 Parameter : " << nParam << endl;
			}
		}, 4);

		Thread3.join();
	}

	//cout << "- 스레드 식별자와 스레드 교환 -" << endl;
	//{
	//	mutex mtx_lock;

	//	int nThreadRunCount1 = 0;
	//	thread Thread1;
	//	Thread1 = thread([&]()
	//	{
	//		_sleep(100);
	//		for (int i = 0; i < 5; ++i)
	//		{
	//			++nThreadRunCount1;
	//			mtx_lock.lock();
	//			cout << "Thread1 ID : " << Thread1.get_id() << endl;
	//			mtx_lock.unlock();
	//		}
	//	});

	//	int nThreadRunCount2 = 0;
	//	thread Thread2;
	//	Thread2 = thread([&]()
	//	{
	//		_sleep(100);
	//		for (int i = 0; i < 5; ++i)
	//		{
	//			++nThreadRunCount2;
	//			mtx_lock.lock();
	//			cout << "Thread2 ID : " << Thread2.get_id() << endl;
	//			mtx_lock.unlock();
	//		}
	//	});

	//	while (nThreadRunCount1 < 3 && nThreadRunCount2 < 3)
	//	{

	//	}

	//	mtx_lock.lock();
	//	cout << "swap 1, 2" << endl;
	//	mtx_lock.unlock();

	//	Thread1.swap(Thread2);
	//	Thread1.join();
	//	Thread2.join();
	//}

	cout << endl << endl;

	cout << "- 하드웨어 쓰레드 수 알기 -" << endl;
	{
		cout << "하드웨어 컨텍스트 수 : " << thread::hardware_concurrency() << endl;
	}
	cout << endl << endl;

	cout << "- lock_guard를 사용하여 자동으로 락을 걸고 해제 -" << endl;
	{
		mutex mtx_lock;
		thread Threads1([&]() {
			for (int i = 0; i < 5; ++i)
			{
				lock_guard<mutex> guard(mtx_lock);
				cout << "Thread Num : " << i << endl;
			}
		});

		thread Threads2;
		Threads2 = thread([&]()
		{
			for (int i = 10; i < 15; ++i)
			{
				lock_guard<mutex> guard(mtx_lock);
				cout << "Thread Num : " << i << endl;
			}
		});

		Threads1.join();
		Threads2.join();
	}
	cout << endl << endl;

	cout << "- 프로그램 실행 중 한 번만 실행하기 -" << endl;
	{
		once_flag p_flag;

		for (int i = 0; i < 7; ++i)
		{
			call_once(p_flag, Test1);
		}
	}
	cout << endl << endl;

	cout << "- thread_local 변수 사용하기 -" << endl;
	{
		thread Thread1, Thread2, Thread3;

		Thread1 = thread([]() {Test2(); });
		Thread2 = thread([]() {Test2(); });
		Thread3 = thread([]() {Test2(); });

		Thread1.join();
		Thread2.join();
		Thread3.join();
	}
	cout << endl << endl;

	cout << "- 이벤트를 사용한 동기화 객체 -" << endl;
	{
		mutex mtx_lock;
		condition_variable Cond;

		thread Thread1([&]()
		{
			for (int i = 1; i < 6; ++i)
			{
				cout << "Thread 1 : " << i << endl;
			}
			Cond.notify_one();
		});

		thread Thread2([&]()
		{
			unique_lock<mutex> uniq_lock(mtx_lock);
			Cond.wait(uniq_lock);

			for (int i = 21; i < 26; ++i)
			{
				cout << "Thread 2 : " << i << endl;
			}
			Cond.notify_one();
		});

		thread Thread3([&]()
		{
			unique_lock<mutex> uniq_lock(mtx_lock);
			Cond.wait(uniq_lock);

			for (int i = 31; i < 36; ++i)
			{
				cout << "Thread 3 : " << i << endl;
			}
			Cond.notify_one();
		});

		Thread1.join();
		Thread2.join();
		Thread3.join();
	}
	return 0;
}