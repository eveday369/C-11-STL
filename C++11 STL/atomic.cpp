#include <iostream>
#include <bitset>
#include <atomic>

using namespace std;

int main()
{
	cout << "- �� ������ �а� ���� -" << endl;
	{
		atomic<int> Num(0);
		cout << Num.load() << endl;

		atomic_store(&Num, 2);
		cout << Num.load() << endl;

		int result = atomic_load(&Num);
		cout << result << endl;

		cout << "�Ϲ������� store, load ����ϱ�" << endl;

		int Num2;
		Num = 5;
		Num2 = Num;
		cout << Num2 << endl;
	}
	cout << endl << endl;

	cout << "- �� ���� ���� -" << endl;
	{
		atomic<int> Num1(10);

		int before = atomic_fetch_add(&Num1, 7);
		cout << "���� �� : " << before << ", ���� �� : " << Num1 << endl;
		cout << endl;

		int a = 0x0b;
		int b = 0x0e;

		atomic<int> Num2(a);

		atomic_fetch_and(&Num2, b);
		cout << "       a : " << bitset<4>(a).to_string() << endl;
		cout << "       b : " << bitset<4>(b).to_string() << endl;
		cout << "AND ���� : " << bitset<4>(Num2).to_string() << endl;
		cout << endl;

		atomic<int> Num3(a);
		atomic_fetch_or(&Num3, b);
		cout << "       a : " << bitset<4>(a).to_string() << endl;
		cout << "       b : " << bitset<4>(b).to_string() << endl;
		cout << "OR ���� : " << bitset<4>(Num3).to_string() << endl;
		cout << endl;

		atomic<int> Num4(a);
		atomic_fetch_xor(&Num4, b);
		cout << "       a : " << bitset<4>(a).to_string() << endl;
		cout << "       b : " << bitset<4>(b).to_string() << endl;
		cout << "XOR ���� : " << bitset<4>(Num4).to_string() << endl;
		cout << endl;
	}
	cout << endl << endl;

	cout << "- �� ������ �� �ٲٱ� -" << endl;
	{
		atomic<int> Num1(10);

		if (atomic_exchange(&Num1, 20) == 10)
		{
			cout << "Num1 10���� " << Num1 << "���� ����" << endl;
		}
		else
		{
			cout << "Num1 ���� ����" << endl;
		}

		atomic<int> Num2(22);

		int expected1 = 22;
		bool result = atomic_compare_exchange_strong(&Num2, &expected1, 1);

		if (result)
		{
			cout << "Num2�� expected1�� ����. Num2 :	" << Num2.load() << endl;
		}
		else
		{
			cout << "Num2�� expected1�� �ٸ���. expected1 : " << expected1 << endl;
		}

		atomic<int> Num3(22);

		int expected2 = 21;
		result = atomic_compare_exchange_strong(&Num3, &expected2, 1);

		if (result)
		{
			cout << "Num3�� expected2�� ����. Num2 :	" << Num2 << endl;
		}
		else
		{
			cout << "Num3�� expected2�� �ٸ���. expected1 : " << expected2 << endl;
		}
	}
	return 0;
}