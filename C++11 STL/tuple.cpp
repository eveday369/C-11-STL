#include <iostream>
#include <string>
#include <tuple>

using namespace std;

struct ITEM
{
	int nID;
};

int main()
{
	ITEM item;
	item.nID = 10001;

	tuple<int, string, ITEM> UserItem = make_tuple(1, "jacking", item);

	cout << get<0>(UserItem) << endl;
	cout << get<1>(UserItem) << endl;
	cout << get<2>(UserItem).nID << endl;

	cout << endl;

	get<0>(UserItem) = 2;
	get<1>(UserItem) = "jacking75";
	get<2>(UserItem).nID = 10002;

	cout << get<0>(UserItem) << endl;
	cout << get<1>(UserItem) << endl;
	cout << get<2>(UserItem).nID << endl;

	cout << endl;

	auto nCount = tuple_size<decltype(UserItem)>::value;
	cout << "tuple UserItem�� ��� ��: " << nCount << endl;

	cout << endl;

	cout << "- ���� �����͸� �����ϴ� tuple -" << endl;
	{
		int nUserIndex = 11;
		string UserName = "jacking";

		auto refUserItem = tie(nUserIndex, UserName);

		cout << get<0>(refUserItem) << endl;
		cout << get<1>(refUserItem) << endl;
	}

	cout << "- tuple�� ����� �����͸� �ϰ������� ������ ��� -" << endl;
	{
		tuple<int, string> UserInfo(1002, "jacking");
		int nUserIndex = 0;
		string UserName;

		tie(nUserIndex, UserName) = UserInfo;

		cout << nUserIndex << endl;
		cout << UserName << endl;
	}

	cout << "- �Ϻ� ��Ҹ� �����ϰ� �ϰ������� ������ ��� -" << endl;
	{
		tuple<int, string, int> UserInfo(1003, "jacking", 22);
		int nUserIndex = 0;
		int nLevel = 0;

		tie(nUserIndex, ignore, nLevel) = UserInfo;

		cout << nUserIndex << endl;
		cout << nLevel << endl;
	}

	cout << endl;

	cout << "- tuple�� tuple ��ġ�� -" << endl;
	{
		tuple<int, string> UserInfo(1003, "jacking");
		tuple<int, int> GameResult(12, 3);
		auto UserGameResult = tuple_cat(UserInfo, GameResult);

		cout << get<0>(UserGameResult) << endl;
		cout << get<1>(UserGameResult) << endl;
		cout << get<2>(UserGameResult) << endl;
		cout << get<3>(UserGameResult) << endl;
	}

	return 0;
}