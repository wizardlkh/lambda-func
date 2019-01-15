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

	auto current = vec.begin();
	while (true) {
		current = find_if(current, vec.end(), [](int i) { return i % 3 == 2; });
		if (current == vec.end()) break;
		cout << "3 으로 나눈 나머지가 2 인 원소는 : " << *current << " 이다 "
			<< endl;
		current++;
	}
}