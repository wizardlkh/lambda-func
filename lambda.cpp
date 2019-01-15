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

	cout << "처음 vec 상태 ------" << endl;
	print(vec.begin(), vec.end());

	cout << "벡터에서 홀수인 원소 ---" << endl;
	int num_erased = 0;

	vec.erase(remove_if(vec.begin(), vec.end(),

		[&num_erased](int i) // 홀수 2개만 제거(return true)
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