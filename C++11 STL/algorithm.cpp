#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

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
	cout << "- 특정 아이템 조사 -" << endl;
	{
		vector<CharItem> CharItemList;
		CharItemList.emplace_back(1, 10);
		CharItemList.emplace_back(2, 5);
		CharItemList.emplace_back(3, 14);
		CharItemList.emplace_back(4, 20);

		cout << "[all_of] 모든 아이템 레벨이 3 이상인가? ";
		cout << all_of(CharItemList.begin(), CharItemList.end(),
			[](CharItem item)
		{
			return (item.Level >= 3) ? true : false;
		}) << endl;
		cout << "[all_of] 모든 아이템 레벨이 10 이상인가? ";
		cout << all_of(CharItemList.begin(), CharItemList.end(), [](CharItem item)
		{
			return (item.Level >= 10) ? true : false;
		}) << endl;
		cout << "[any_of] 모든 아이템 레벨이 20 이상인가? ";
		cout << any_of(CharItemList.begin(), CharItemList.end(), [](CharItem item)
		{
			return (item.Level >= 20) ? true : false;
		}) << endl;
		cout << "[none_of] 모든 아이템 레벨이 3 이상인가? ";
		cout << none_of(CharItemList.begin(), CharItemList.end(), [](CharItem item)
		{
			return (item.Level >= 3) ? true : false;
		}) << endl;
	}
	cout << endl << endl;

	cout << "- 아이템 리스트에서 3개만 복사하기 -" << endl;
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
			cout << "아이템 ID : " << item.ItemID << ", 레벨 : " << item.Level << endl;
		}
	}
	cout << endl << endl;

	cout << "- 레벨이 10보다 낮은 아이템 찾기 -" << endl;
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
			cout << "아이템 ID : " << iter->ItemID << ", 레벨 : " << iter->Level << endl;
		}
	}
	cout << endl << endl;

	cout << "- 게임 아이템을 팔 수 있는 것과 팔 수 없는 것으로 나누기 -" << endl;
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

		cout << "팔 수 있는 아이템" << endl;
		for (auto& item : SellItems)
		{
			if (item.nItemCode <= 0)
			{
				continue;
			}
			cout << "아이템 코드 : " << item.nItemCode << endl;
		}
		cout << endl << endl;

		cout << "팔 수 없는 아이템" << endl;
		for (auto iter = UnSellItems.begin(); iter != UnSellItems.end(); ++iter)
		{
			if (iter->nItemCode <= 0)
			{
				continue;
			}
			cout << "아이템 코드 : " << iter->nItemCode << endl;
		}
	}
	cout << endl << endl;

	return 0;
}