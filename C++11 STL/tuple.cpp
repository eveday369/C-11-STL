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
	cout << "tuple UserItem의 요소 수: " << nCount << endl;

	cout << endl;

	cout << "- 참조 데이터를 저장하는 tuple -" << endl;
	{
		int nUserIndex = 11;
		string UserName = "jacking";

		auto refUserItem = tie(nUserIndex, UserName);

		cout << get<0>(refUserItem) << endl;
		cout << get<1>(refUserItem) << endl;
	}

	cout << "- tuple에 저장된 데이터를 일괄적으로 변수에 담기 -" << endl;
	{
		tuple<int, string> UserInfo(1002, "jacking");
		int nUserIndex = 0;
		string UserName;

		tie(nUserIndex, UserName) = UserInfo;

		cout << nUserIndex << endl;
		cout << UserName << endl;
	}

	cout << "- 일부 요소를 무시하고 일괄적으로 변수에 담기 -" << endl;
	{
		tuple<int, string, int> UserInfo(1003, "jacking", 22);
		int nUserIndex = 0;
		int nLevel = 0;

		tie(nUserIndex, ignore, nLevel) = UserInfo;

		cout << nUserIndex << endl;
		cout << nLevel << endl;
	}

	cout << endl;

	cout << "- tuple과 tuple 합치기 -" << endl;
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