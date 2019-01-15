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

struct User {
	string name;
	int level;

	User(string name, int level) : name(name), level(level) {}
	bool operator==(const User& user) const {
		if (name == user.name && level == user.level) return true;
		return false;
	}
};

class Party {
	vector<User> users;
public:
	bool add_user(string name, int level) 
	{
		User new_user(name, level);
		if (find(users.begin(), users.end(), new_user) != users.end()) // ���� ��ü�� ������
		{
			return false;
		}
		users.push_back(new_user);
		return true;
	}

	// ��Ƽ�� ��ΰ� 15 ���� �̻��̿����� ���� ���� ����
	bool can_join_dungeon() {
		return all_of(users.begin(), users.end(), [](User& user) {
			return user.level >= 15;
		});
	}

	// ��Ƽ�� �� �Ѹ� �̶� 19�� �̻��̸� Ư�� ������ ��� ����
	bool can_use_special_item() {
		return any_of(users.begin(), users.end(), [](User& user) {
			return user.level >= 19;
		});
	}
};
int main() {
	Party party;
	party.add_user("ö��", 15);
	party.add_user("����", 18);
	party.add_user("�μ�", 12);
	party.add_user("����", 19);


	cout << boolalpha;
	cout << "���� ���� ���� ? " << party.can_join_dungeon() << endl;
	cout << "Ư�� ������ ��� ���� ? " << party.can_use_special_item() << endl;
}