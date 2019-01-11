#include <iostream>
#include <string>

using namespace std;


class map {
private:
	static const int tableSize = 16; 
	struct item {
		string key;
		int value;
		item* next;
	};
	item* Table[tableSize];
public:
	map();
	int func(string key);
	void addItem(string name, int points);
	int getKey(string name);
};

map::map() {
	for (int i = 0; i < tableSize; i++) {
		Table[i] = new item;
		Table[i]->key = "none";
		Table[i]->value = 0;
		Table[i]->next = nullptr;
	}
}

int map::func(string key) {
	int hash = 0;
	int bucket;
	for (int i = 0; i < key.length(); i++) { 
		hash += (int)key[i];
		
	}
	bucket = hash % tableSize;
	return bucket;
}

void map::addItem(string name, int points) {
	int bucket = func(name);
	if (Table[bucket]->key == "none") {
		Table[bucket]->key = name;
		Table[bucket]->value = points;
	}
	else {
		item* pointer = Table[bucket];
		item* tmp = new item;
		tmp->key = name;
		tmp->value = points;
		tmp->next = nullptr;
		while (pointer->next != nullptr) {
			pointer = pointer->next;
		}
		pointer->next = tmp;
	}
}

int map::getKey(string name) {
	int bucket = func(name);
	bool found = false;
	item* ptr = Table[bucket];
	while (ptr != nullptr) {
		if (ptr->key == name) {
			found = true;
			return ptr->value;
		}
		ptr = ptr->next;
	}
	if (found == false) {
		return -1;
	}
}

int main() {
	map test;
	int a, b, c, d, e, f;
	test.addItem("Mike", 15);
	test.addItem("Guffy", 15);
	test.addItem("Antony", 0);
	test.addItem("John", 30);
	test.addItem("Dennis", 20);
	a = test.getKey("Mike");
	b = test.getKey("Guffy");
	c = test.getKey("Dennis");
	d = test.getKey("John");
	e = test.getKey("Antony");
	f = test.getKey("Malia");
	cout << a << " " << b << " " << c << " " << d << " " << e << " " << f;
	return 0;
}
