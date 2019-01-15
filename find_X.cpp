#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <typename Iter>

void print(Iter begin, Iter end) {
	while (begin != end) {
		cout << "[" << *begin << "] ";
		begin++;
	}
	cout << endl;
}

int main() {
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	
	for (int i = 0; i < vec.size() ; i++)
	{
		auto result = find(vec.begin(), vec.end(), vec.at(i) );
		cout << vec.at(i) << "은(는) " << "vec[" << distance(vec.begin(), result) << "]" << '\n';
	}
	// 중복된 값이 있으면 앞에서 반복자의 특성때문에 vec[1] 만 나옴 , vec[4]까지 탐색X	
}