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

	cout << "���� ��ü�� 1 �� ���Ѵ�" << endl;
	transform(vec.begin(), vec.end(), vec.begin(), [](int i) { return i + 1; });
	print(vec.begin(), vec.end());
}