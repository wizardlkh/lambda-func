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

	for (int i = 0; i < vec.size(); i++)
	{
		auto current = vec.begin() + i;

		while (true) {
			current = find(current, vec.end(), vec.at(i));
			if (current == vec.end())
				break;
			cout << vec.at(i) << "Àº(´Â) " << "vec[" << distance(vec.begin(), current) << "]" << '\n';
			current++;
		}
	}
}