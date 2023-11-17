#include <iostream>

using namespace std;

struct node {
	int _info;
	node* _next;

	node() { }

	node(int info, node* next) {
		_info = info;
		_next = next;
	}
};

class priorityQueueLinkedList {
	node* first = nullptr;
	int counter = 0;
public:
	void insert(int info) {
		node* t = first;
		node* pt = nullptr;
		counter++;

		while (t != nullptr) {
			if (t->_info < info)
				break;

			pt = t;
			t = t->_next;
		}

		node* n = new node(info, t);

		if (pt == nullptr) {
			first = n;
		}
		else {
			pt->_next = n;
		}
	}

	int remove() {
		if (isEmpty() == true) {
			cout << "The queue is empty! ";
			return 0;
		}

		node* t = first;

		first = first->_next;

		int removed = t->_info;

		delete t;

		counter--;
		return removed;
	}

	bool isEmpty() {
		if (counter == 0)
			return true;
		return false;
	}

	int getCounter() {
		return counter;
	}

	void print() {
		node* t = first;

		while (t != nullptr) {
			cout << t->_info << " ,";
			t = t->_next;
		}

		cout << '\n';
	}
};

int main() {
	int selector = 9;
	priorityQueueLinkedList queue;

	do {
		cout << "1 -> Insert number\n";
		cout << "2 -> Remove number\n";
		cout << "3 -> Check if empty\n";
		cout << "4 -> Get counter\n";
		cout << "5 -> Print\n";
		cout << "0 -> Exit\n";
		cin >> selector; cout << '\n';

		switch (selector) {
		case 1: {int info; cout << "Enter: "; cin >> info; queue.insert(info); }break;
		case 2: {cout << "The removed number is: " << queue.remove() << '\n'; }break;
		case 3: {if (queue.isEmpty()) cout << "The queue is empty!\n"; else cout << "The queue is not empty!\n"; }break;
		case 4: {cout << "The counter is at: " << queue.getCounter() << '\n'; }break;
		case 5: {cout << "Queue: "; queue.print(); }break;
		case 0: break;
		}

		cout << '\n';
	} while (selector != 0);

	system("pause>nul");
	return 0;
}
