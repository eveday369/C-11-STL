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

	return 0;
}