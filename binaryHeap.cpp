#include <iostream>

using namespace std;

class maxBinaryHeap {
	int max;
	int* pArray;
	int counter = 0;

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	void reconstructUpward(int index) {
		if (index == 1)
			return;

		int parent = index / 2;

		if (pArray[index] > pArray[parent]) {
			swap(pArray[index], pArray[parent]);
			reconstructUpward(parent);
		}
	}

	void reconstructDownward(int index) {
		if (index * 2 > counter)
			return;

		int leftChild = index * 2;
		int rightChild = leftChild + 1;
		int maxIndex = index;

		if (pArray[leftChild] > pArray[index]) 
			maxIndex = leftChild;
		
		if (rightChild <= counter && pArray[rightChild] > pArray[maxIndex])
			maxIndex = rightChild;

		if (maxIndex != index) {
			swap(pArray[index], pArray[maxIndex]);
			reconstructDownward(maxIndex);
		}
	}
public:
	maxBinaryHeap(int max = 100) {
		this->max = max;
		pArray = new int[max + 1];
		counter = 0;
	}

	void insert(int value) {
		if (counter == max) {
			cout << "The queue is full! ";
			return;
		}

		counter++;
		pArray[counter] = value;
		reconstructUpward(counter);
	}

	int remove() {
		if (counter == 0) {
			cout << "The queue is empty! ";
			return 0;
		}

		int removed = pArray[1];
		pArray[1] = pArray[counter];
		counter--;
		reconstructDownward(1);

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
		for (int i = 1; i <= counter; i++)
			cout << pArray[i] << " ,";
		cout << '\n';
	}
};

int main() {
	int selector = 9;
	maxBinaryHeap queue(100);

	do {
		cout << "1 -> Insert number\n";
		cout << "2 -> Remove number\n";
		cout << "3 -> Check if empty\n";
		cout << "4 -> Get counter\n";
		cout << "5 -> Print\n";
		cout << "0 -> Exit\n";
		cin >> selector; cout << '\n';

		switch (selector) {
		case 1: {int value; cout << "Enter: "; cin >> value; queue.insert(value); }break;
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
