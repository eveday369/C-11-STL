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

	// 추가
	GameCharacter Character1(12, 7, 1000);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(12, Character1));
	GameCharacter Character2(15, 20, 111000);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(15, Character2));
	GameCharacter Character3(200, 34, 3345000);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(200, Character3));

	// iterator와 begin, end를 사용하여 저장한 요소를 정방향으로 순회
	for (auto iter1 = Characters.begin(); iter1 != Characters.end(); ++iter1)
	{
		cout << "캐릭터 코드 : " << iter1->second._CharCd;
		cout << " | 레벨 : " << iter1->second._Level;
		cout << " | 가진 돈 : " << iter1->second._Money << endl;
	}
	cout << endl << endl;

	// Characters에 저장한 요소 수
	int CharacterCount = Characters.size();

	// 검색
	auto FindIter = Characters.find(15);

	// 찾지 못하면 FindIter는 end 위치의 반복자 반환
	if (Characters.end() == FindIter)
	{
		cout << " 캐릭터 코드가 15인 캐릭터가 없습니다" << endl;
	}
	else
	{
		cout << " 캐릭터 코드가 15인 캐릭터를 찾았습니다" << endl;
		cout << " 캐릭터 코드 : " << FindIter->second._CharCd;
		cout << " | 레벨 : " << FindIter->second._Level;
		cout << " | 가진 돈 : " << FindIter->second._Money;
	}
	cout << endl << endl;

	for (auto iter1 = Characters.begin(); iter1 != Characters.end(); ++iter1)
	{
		cout << "캐릭터 코드 : " << iter1->second._CharCd;
		cout << " | 레벨 : " << iter1->second._Level;
		cout << " | 가진 돈 : " << iter1->second._Money << endl;
	}
	cout << endl << endl;
	
	cout << "캐릭터 코드가 15인 캐릭터 삭제" << endl;
	Characters.erase(15);

	for (auto iter1 = Characters.begin(); iter1 != Characters.end(); ++iter1)
	{
		cout << "캐릭터 코드 : " << iter1->second._CharCd;
		cout << " | 레벨 : " << iter1->second._Level;
		cout << " | 가진 돈 : " << iter1->second._Money << endl;
	}
	cout << endl << endl;

	// 모든 캐릭터 삭제
	Characters.erase(Characters.begin(), Characters.end());

	if (Characters.empty())
	{
		cout << "Characters는 비어 있습니다" << endl;
	}

	GameCharacter Character4(12, 7, 1000);
	Characters.insert(pair<int, GameCharacter>(12, Character4));
	GameCharacter Character5(10, 9, 11000);
	Characters[1] = Character5;

	for (auto iter1 = Characters.begin(); iter1 != Characters.end(); ++iter1)
	{
		cout << "캐릭터 코드 : " << iter1->second._CharCd;
		cout << " | 레벨 : " << iter1->second._Level;
		cout << " | 가진 돈 : " << iter1->second._Money << endl;
	}

	return 0;
}