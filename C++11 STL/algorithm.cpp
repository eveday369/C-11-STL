#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>

using namespace std;

struct PLAYER
{
	int CharCD;
	bool IsRedTeam;
};

struct ITEM
{
	int nItemCode;
	bool bEnableSell;
};

struct CharItem
{
	CharItem(int id, int level)
	{
		ItemID = id;
		Level = level;
	}

	int ItemID;
	int Level;
};

int main()
{
	cout << "- Ư�� ������ ���� -" << endl;
	{
		vector<CharItem> CharItemList;
		CharItemList.emplace_back(1, 10);
		CharItemList.emplace_back(2, 5);
		CharItemList.emplace_back(3, 14);
		CharItemList.emplace_back(4, 20);

		cout << "[all_of] ��� ������ ������ 3 �̻��ΰ�? ";
		cout << all_of(CharItemList.begin(), CharItemList.end(),
			[](CharItem item)
		{
			return (item.Level >= 3) ? true : false;
		}) << endl;
		cout << "[all_of] ��� ������ ������ 10 �̻��ΰ�? ";
		cout << all_of(CharItemList.begin(), CharItemList.end(), [](CharItem item)
		{
			return (item.Level >= 10) ? true : false;
		}) << endl;
		cout << "[any_of] ��� ������ ������ 20 �̻��ΰ�? ";
		cout << any_of(CharItemList.begin(), CharItemList.end(), [](CharItem item)
		{
			return (item.Level >= 20) ? true : false;
		}) << endl;
		cout << "[none_of] ��� ������ ������ 3 �̻��ΰ�? ";
		cout << none_of(CharItemList.begin(), CharItemList.end(), [](CharItem item)
		{
			return (item.Level >= 3) ? true : false;
		}) << endl;
	}
	cout << endl << endl;

	cout << "- ������ ����Ʈ���� 3���� �����ϱ� -" << endl;
	{
		vector<CharItem> CharItemList;
		CharItemList.emplace_back(1, 10);
		CharItemList.emplace_back(2, 5);
		CharItemList.emplace_back(3, 14);
		CharItemList.emplace_back(4, 20);

		vector<CharItem> CharItemList2;
		copy_n(CharItemList.begin(), 3, back_inserter(CharItemList2));

		for (auto item : CharItemList2)
		{
			cout << "������ ID : " << item.ItemID << ", ���� : " << item.Level << endl;
		}
	}
	cout << endl << endl;

	cout << "- ������ 10���� ���� ������ ã�� -" << endl;
	{
		vector<CharItem> CharItemList;
		CharItemList.emplace_back(1, 10);
		CharItemList.emplace_back(2, 5);
		CharItemList.emplace_back(3, 14);
		CharItemList.emplace_back(4, 2);
		CharItemList.emplace_back(5, 20);

		auto iter = find_if_not(CharItemList.begin(), CharItemList.end(), [](CharItem item)
		{
			return item.Level >= 10;
		});

		if(iter != CharItemList.end())
		{
			cout << "������ ID : " << iter->ItemID << ", ���� : " << iter->Level << endl;
		}
	}
	cout << endl << endl;

	cout << "- ���� �������� �� �� �ִ� �Ͱ� �� �� ���� ������ ������ -" << endl;
	{
		vector<ITEM> AllItems;
		ITEM item1; item1.nItemCode = 1; item1.bEnableSell = false;
		AllItems.push_back(item1);
		ITEM item2; item2.nItemCode = 2; item2.bEnableSell = true;
		AllItems.push_back(item2);
		ITEM item3; item3.nItemCode = 3; item3.bEnableSell = true;
		AllItems.push_back(item3);
		ITEM item4; item4.nItemCode = 4; item4.bEnableSell = false;
		AllItems.push_back(item4);
		ITEM item5; item5.nItemCode = 5; item5.bEnableSell = true;
		AllItems.push_back(item5);
		ITEM item6; item6.nItemCode = 6; item6.bEnableSell = false;
		AllItems.push_back(item6);
		ITEM item7; item7.nItemCode = 7; item7.bEnableSell = true;
		AllItems.push_back(item7);
		
		ITEM UnItem; UnItem.nItemCode = 0;
		list< ITEM > SellItems(7, UnItem);
		list< ITEM > UnSellItems(7, UnItem);
		
		pair<list<ITEM>::iterator, list<ITEM>::iterator> SeperateItems;
		SeperateItems = partition_copy(AllItems.begin(), AllItems.end(),
			SellItems.begin(), UnSellItems.begin(), [](ITEM& item)
		{
			return item.bEnableSell;
		});

		cout << "�� �� �ִ� ������" << endl;
		for (auto& item : SellItems)
		{
			if (item.nItemCode <= 0)
			{
				continue;
			}
			cout << "������ �ڵ� : " << item.nItemCode << endl;
		}
		cout << endl << endl;

		cout << "�� �� ���� ������" << endl;
		for (auto iter = UnSellItems.begin(); iter != UnSellItems.end(); ++iter)
		{
			if (iter->nItemCode <= 0)
			{
				continue;
			}
			cout << "������ �ڵ� : " << iter->nItemCode << endl;
		}
	}
	cout << endl << endl;

	cout << "- �÷��̾� �� ���� -" << endl;
	{
		vector< PLAYER > StagePlayers1;
		PLAYER player1; player1.CharCD = 1; player1.IsRedTeam = true;
		StagePlayers1.push_back(player1);
		PLAYER player2; player2.CharCD = 2; player2.IsRedTeam = true;
		StagePlayers1.push_back(player2);
		PLAYER player3; player3.CharCD = 3; player3.IsRedTeam = true;
		StagePlayers1.push_back(player3);
		PLAYER player4; player4.CharCD = 4; player4.IsRedTeam = false;
		StagePlayers1.push_back(player4);
		PLAYER player5; player5.CharCD = 5; player5.IsRedTeam = false;
		StagePlayers1.push_back(player5);
		PLAYER player6; player6.CharCD = 6; player6.IsRedTeam = false;
		StagePlayers1.push_back(player6);
		PLAYER player7; player7.CharCD = 7; player7.IsRedTeam = false;
		StagePlayers1.push_back(player7);
		
		bool IsPartitioned = is_partitioned(StagePlayers1.begin(), StagePlayers1.end(),
			[](PLAYER player) -> bool { return player.IsRedTeam; });
		if (IsPartitioned)
		{
			cout << "���� ���� ��� ������ �������� �ֽ��ϴ�." << endl;
		}
		else
		{
			cout << "���� ���� ��� ������ �������� ���� �ʽ��ϴ�." << endl;
		}

		vector<PLAYER>::iterator IterFirstBlueTeamPlayer = partition_point(StagePlayers1.begin(), StagePlayers1.end(),
			[](PLAYER player)->bool {return player.IsRedTeam; });
		cout << "ù ���� ��� �� �÷��̾�. ĳ���� �ڵ� : " << (*IterFirstBlueTeamPlayer).CharCD << endl;
	}
	cout << endl << endl;

	cout << "- ���� ���� ���� -" << endl;
	{
		int Numbers1[5] = { 1, 2, 3, 4, 5 };
		int Numbers2[5] = { 5, 4, 3, 2, 1 };
		int Numbers3[5] = { 1, 2, 4, 3, 5 };
		bool IsResult = false;

		IsResult = is_sorted(&Numbers1[0], &Numbers1[5], [](int x, int y)
		{
			return x < y;
		});
		cout << "Numbers1. ��������? " << IsResult << endl;
		IsResult = is_sorted(&Numbers2[0], &Numbers2[5], [](int x, int y)
		{
			return x > y;
		});
		cout << "Numbers2. ��������? " << IsResult << endl;
		IsResult = is_sorted(&Numbers3[0], &Numbers3[5], [](int x, int y)
		{
			return x < y;
		});
		cout << "Numbers3. ��������? " << IsResult << endl;
		int Numbers4[8] = { 1,2,3,5,4,5,7,8 };
		int* NumIter = is_sorted_until(&Numbers4[0], &Numbers4[5], [](int x, int y)
		{
			return x < y;
		});
		cout << "Numbers4���� ���ĵ��� ���� ù ��° ��ġ�� �� : " << *NumIter << endl;
	}
	cout << endl << endl;

	cout << "- ��Ҹ� �������� ������ ä��� -" << endl;
	{
		vector<int> Numberlist;
		Numberlist.push_back(2);
		Numberlist.push_back(5);
		Numberlist.push_back(7);
		iota(Numberlist.begin(), Numberlist.end(), 2);

		for (auto iter : Numberlist)
		{
			cout << iter << endl;
		}
	}
	cout << "- �ִ밪, �ּҰ� ���ϱ� -" << endl;
	{
		cout << "std::min" << endl;
		cout << min({ 10, 15, 1, 5, 2 }) << endl;
		cout << endl;
		cout << "std::max" << endl;
		cout << max({ 10, 15, 1, 5, 2 }) << endl;
		cout << endl;
		auto value = minmax({ 10, 15, 1, 5, 2 });
		cout << "std::minmax" << endl;
		cout << "�ּҰ�, �ְ� : " << value.first << ", " <<value.second << endl;
		cout << endl;
	}

	return 0;
}