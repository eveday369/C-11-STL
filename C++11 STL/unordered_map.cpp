#include <iostream>
#include <unordered_map>

using namespace std;

struct GameCharacter
{
	GameCharacter() {}
	GameCharacter(int CharCd, int Level, int Money)
	{
		_CharCd = CharCd;
		_Level = Level;
		_Money = Money;
	}

	int _CharCd;
	int _Level;
	int _Money;
};

int main()
{
	unordered_map<int, GameCharacter> Characters;

	// �߰�
	GameCharacter Character1(12, 7, 1000);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(12, Character1));
	GameCharacter Character2(15, 20, 111000);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(15, Character2));
	GameCharacter Character3(200, 34, 3345000);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(200, Character3));

	// iterator�� begin, end�� ����Ͽ� ������ ��Ҹ� ���������� ��ȸ
	for (auto iter1 = Characters.begin(); iter1 != Characters.end(); ++iter1)
	{
		cout << "ĳ���� �ڵ� : " << iter1->second._CharCd;
		cout << " | ���� : " << iter1->second._Level;
		cout << " | ���� �� : " << iter1->second._Money << endl;
	}
	cout << endl << endl;

	// Characters�� ������ ��� ��
	int CharacterCount = Characters.size();

	// �˻�
	auto FindIter = Characters.find(15);

	// ã�� ���ϸ� FindIter�� end ��ġ�� �ݺ��� ��ȯ
	if (Characters.end() == FindIter)
	{
		cout << " ĳ���� �ڵ尡 15�� ĳ���Ͱ� �����ϴ�" << endl;
	}
	else
	{
		cout << " ĳ���� �ڵ尡 15�� ĳ���͸� ã�ҽ��ϴ�" << endl;
		cout << " ĳ���� �ڵ� : " << FindIter->second._CharCd;
		cout << " | ���� : " << FindIter->second._Level;
		cout << " | ���� �� : " << FindIter->second._Money;
	}
	cout << endl << endl;

	for (auto iter1 = Characters.begin(); iter1 != Characters.end(); ++iter1)
	{
		cout << "ĳ���� �ڵ� : " << iter1->second._CharCd;
		cout << " | ���� : " << iter1->second._Level;
		cout << " | ���� �� : " << iter1->second._Money << endl;
	}
	cout << endl << endl;
	
	cout << "ĳ���� �ڵ尡 15�� ĳ���� ����" << endl;
	Characters.erase(15);

	for (auto iter1 = Characters.begin(); iter1 != Characters.end(); ++iter1)
	{
		cout << "ĳ���� �ڵ� : " << iter1->second._CharCd;
		cout << " | ���� : " << iter1->second._Level;
		cout << " | ���� �� : " << iter1->second._Money << endl;
	}
	cout << endl << endl;

	// ��� ĳ���� ����
	Characters.erase(Characters.begin(), Characters.end());

	if (Characters.empty())
	{
		cout << "Characters�� ��� �ֽ��ϴ�" << endl;
	}

	GameCharacter Character4(12, 7, 1000);
	Characters.insert(pair<int, GameCharacter>(12, Character4));
	GameCharacter Character5(10, 9, 11000);
	Characters[1] = Character5;

	for (auto iter1 = Characters.begin(); iter1 != Characters.end(); ++iter1)
	{
		cout << "ĳ���� �ڵ� : " << iter1->second._CharCd;
		cout << " | ���� : " << iter1->second._Level;
		cout << " | ���� �� : " << iter1->second._Money << endl;
	}

	return 0;
}