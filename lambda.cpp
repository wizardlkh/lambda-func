#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

template<typename Iter>

void print(Iter begin, Iter end)
{
	while (begin != end) {

		cout << "[" << *begin << "] ";

		begin++;

	}
	cout << endl;

}

int main()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	cout << "ó�� vec ���� ------" << endl;
	print(vec.begin(), vec.end());

	cout << "���Ϳ��� Ȧ���� ���� ---" << endl;
	int num_erased = 0;

	vec.erase(remove_if(vec.begin(), vec.end(),

		[&num_erased](int i) // Ȧ�� 2���� ����(return true)
		{
			if (num_erased >= 2) 
				return false;
			else if (i % 2 == 1) 
			{
				num_erased++;
				return true;
			}

			return false;

		}), vec.end());

	print(vec.begin(), vec.end());
}