#include <iostream>
#include <future>
#include <thread>
#include <vector>
#include <utility>

using namespace std;

vector<int> GetCharItems(int CharCd)
{
	auto ThreadID = this_thread::get_id();
	cout << "GetCharItems 스레드 ID : " << ThreadID << endl;
	vector<int> itemlist;

	for (int i = 1; i <= 5; ++i)
	{
		itemlist.push_back(i);
	}

	return itemlist;
}

void GetCharItem(promise<vector<int>>& ItemList)
{
	auto ThreadID = this_thread::get_id();
	cout << "GetCharItems 스레드 ID : " << ThreadID << endl;
	vector<int> itemlist;

	for (int i = 0; i <= 5; ++i)
	{
		itemlist.push_back(i);
	}
	ItemList.set_value(move(itemlist));
}

int GetMoneFromDB(int CharCd)
{
	auto ThreadID = this_thread::get_id();
	cout << "GetMemoryFromDB. Thread ID: " << ThreadID << endl;
	return CharCd;
}

int main()
{
	cout << "- 비동기로 함수 실행 -" << endl;
	{
		auto ThreadID = this_thread::get_id();
		cout << "메인 스레드 ID : " << ThreadID << endl;
		cout << "async(launch::async, GetMoneFromDB)" << endl;
		future<int> future1 = async(launch::async, GetMoneFromDB, 10);
		this_thread::sleep_for(chrono::milliseconds(10));
		cout << "메인 스레드에서 10msec 대기" << endl;

		auto result1 = future1.get();
		cout << "GetMoneyFromDB의 반환값" << result1 << endl;
		cout << endl;

		cout << "async(launch::deferred, GetMoneFromDB)" << endl;
		future<int> future2 = async(launch::deferred, GetMoneFromDB, 10);
		this_thread::sleep_for(chrono::milliseconds(10));
		cout << "메인 스레드에서 10msec 대기" << endl;

		auto result2 = future2.get();
		cout << "GetMoneyFromDB의 반환값" << result2 << endl;
	}
	cout << endl << endl;

	cout << "- promise와 future로 다른 스레드의 실행 결과 얻기 -" << endl;
	{
		auto ThreadID = this_thread::get_id();
		cout << "메인 스레드 ID : " << ThreadID << endl;
		promise<vector<int>> ItemList;
		future<vector<int>> f = ItemList.get_future();

		auto t = thread(&GetCharItem, ref(ItemList));
		t.detach();

		auto result = f.get();

		for (auto ItemCode : result)
		{
			cout << "캐릭터의 아이템 : " << ItemCode << endl;
		}
	}
	cout << endl << endl;

	cout << "- task 방식으로 비동기 실행 -" << endl;
	{
		auto ThreadID = this_thread::get_id();
		cout << "메인 스레드 ID : " << ThreadID << endl;

		packaged_task<vector<int>(int)>task(&GetCharItems);
		future<vector<int>> f = task.get_future();
		thread t(move(task), 11);

		t.detach();

		auto result = f.get();

		for (auto ItemCode : result)
		{
			cout << "캐릭터의 아이템 : " << ItemCode << endl;
		}
	}

	return 0;
}