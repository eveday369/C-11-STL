#include <iostream>
#include <array>

using namespace std;

int main()
{
	cout << "- array�� ��� ���� ��� -" << endl;
	{
		array<int, 5> arr1;

		for (int i = 0; i < 5; ++i)
		{
			arr1[i] = i + 1;
		}

		for_each(arr1.begin(), arr1.end(), [](int i)
		{
			cout << i << endl;
		});

		cout << endl;

		cout << arr1.at(2) << endl;
		cout << arr1.front() << endl;
		cout << arr1.back() << endl;

		int* pData = arr1.data();
		cout << pData[3] << endl;
	}

	cout << endl;

	cout << "- array�� ũ�� �˱� -" << endl;
	{
		array<int, 3> arr1 = { 1, 2, 3 };
		cout << arr1.size() << endl;
	}

	cout << endl;

	cout << "- array�� Ư���� ä��� -" << endl;
	{
		array<int, 3> arr1;
		arr1.fill(11);
		for_each(arr1.begin(), arr1.end(), [](int i)
		{
			cout << i << endl;
		});
	}

	return 0;
}