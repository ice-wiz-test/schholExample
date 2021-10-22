#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <deque>
#include <string>
#include <ctime>
using namespace std;
template <typename T>
class Node {
public:
	Node* leftptr; 
	Node* rightptr;
	T value;
	Node(T value, Node* newLeft);

	Node(T value, Node* newLeft, Node* newRight);

	Node(Node* newLeft, Node* newRight);
};

template <typename T>
//TODO - this could be optimized if we look where are we closer to, head or tail.
class LinkedList {
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int sz = 0;
public:

	Node<T>* const getHead() { return head; }
	int size() const { return sz; }

	bool isEmpty() const { return sz = 0; }

	void addFront(T value);

	void addBack(T value);

	void deleteFront();

	void deleteBack();

	void addIndex(int index, T val);

	void deleteIndex(int index);

	void deleteVal(T val);

	int findVal(T val);

	void debugPutOut();

	const T operator[](int n);

	template <typename Type> friend ostream& operator <<(ostream&, LinkedList<Type>&);
	template <typename Type> friend LinkedList<Type>* mergeSortNew(LinkedList<Type>*);
};

template <typename T>

Node<T>::Node(T val, Node* newLeft) {
	value = val;
	leftptr = newLeft;
}

template <typename T>

Node<T>::Node(T val, Node* newLeft, Node* newRight) {
	value = val;
	leftptr = newLeft;
	rightptr = newRight;
}
template <typename T>
Node<T>::Node( Node* newLeft, Node* newRight) {
	leftptr = newLeft;
	rightptr = newRight;
}


template <typename T>

void LinkedList<T>::addFront(T value) {
	if (head != nullptr) {
		Node<T>* hd = head;

		Node<T>* pnode = new Node<T>(value, nullptr, nullptr);
		hd->leftptr = pnode;

		pnode->rightptr = hd;
		head = pnode;
		sz++;
	}
	else {
		Node<T>* pnode = new Node<T>(value, nullptr, nullptr);
		head = pnode;
		tail = pnode;
		sz++;
	}
}

template <typename T>

void LinkedList<T>::addBack(T value) {
	if (tail != nullptr) {
		Node<T>* tl = tail;

		Node<T>* pnode = new Node<T>(value, nullptr, nullptr);
		tl->rightptr = pnode;

		pnode->leftptr = tl;
		tail = pnode;
		sz++;
	}
	else {
		Node<T>* pnode = new Node<T>(value, nullptr, nullptr);
		tail = pnode;
		head = pnode;
		sz++;
	}
}

template <typename T>

void LinkedList<T>::deleteFront() {
	if (sz == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
		sz--;
	}
	else {
		sz--;
		Node<T>* pnode = head->rightptr;
		delete head;
		pnode->leftptr = nullptr;
		head = pnode;
		if (sz == 0) tail = nullptr;
	}
}


template <typename T>

void LinkedList<T>::deleteBack() {
	if (sz == 1) {
		delete tail;
		tail = nullptr;
		head = nullptr;
		sz--;
	}
	else {
		sz--;
		Node<T>* pnode = tail->leftptr;
		delete tail;
		tail = pnode;
		pnode->leftptr = nullptr;
		if (sz == 0) head = nullptr;
	}
}

template <typename T>
void LinkedList<T>::addIndex(int index, T value) {
	if (index >= sz) return;

	int cnt = 0;
	Node<T>* curr = head;
	while (cnt != index) {
		curr = curr->rightptr;
		cnt++;
	}
	if (index == 0) {
		addFront(value);
		return;
	}
	if (index == sz) {
		addBack(value);
		return;
	}

	Node<T>* pnode = new Node<T>(value, nullptr, nullptr);
	pnode->leftptr = curr->leftptr;
	pnode->rightptr = curr;
	Node<T>* lft = curr->leftptr;
	lft->rightptr = pnode;
	curr->leftptr = pnode;
	sz++;
	return;
}

template <typename T>

void LinkedList<T>::deleteIndex(int index) {
	if (index == 0) {
		deleteFront();
		return;
	}

	if (index == sz - 1) {
		deleteBack();
		return;
	}

	if (index > sz - 1) return;

	int cnt = 0;
	Node<T>* curr = head;
	while (cnt != index) {
		curr = curr->rightptr;
		cnt++;
	}

	(curr->leftptr)->rightptr = curr->rightptr;
	(curr->rightptr)->leftptr = curr->leftptr;
	sz--;
	return;
}

template <typename T>
void LinkedList<T>::deleteVal(T value) {
	while (sz > 0 && head->value == value) {
		head->rightptr->leftptr = nullptr;
		delete head;
		sz--;
	}
	while (sz > 0 && tail->value == value) {
		tail->leftptr->rightptr = nullptr;
		delete tail;
		sz--;
	}

	Node<T>* curr = head;
	while (curr != nullptr) {
		if (curr->value == value) {
			(curr->leftptr)->rightptr = curr->rightptr;
			(curr->rightptr)->leftptr = curr->leftptr;
			sz--;
		}
		curr = curr->rightptr;
	}
}

template <typename T> 
int LinkedList<T>::findVal(T value) {
	Node<T>* curr = head;
	if (sz == 0) return -1;

	int cnt = 0;
	while (curr->value != value) {
		curr = curr->rightptr;
		cnt++;
	}
	if (cnt == sz) return -1;
	return cnt;
}

template <typename T>
void LinkedList<T>::debugPutOut() {
	Node<T>* curr = head;
	while (curr != nullptr) {
		cout << curr->value << " <-> ";
		curr = curr->rightptr;
	}
	cout << endl;
}

template <typename T>

const T LinkedList<T>::operator[](int num) {
	if (num >= sz) return nullptr;

	int cnt = 0; 
	Node<T>* curr = head;
	while (cnt != num) {
		curr = curr->rightptr;
	}
	return curr->value;
}
template <typename T>
ostream& operator<<(ostream& out, LinkedList<T>& a) {
	Node<T>* curr = a.head;
	for (int i = 0; i < a.size(); ++i) {
		out << curr->value << " <-> ";
		curr = curr->rightptr;
	}
	return out;
}

template <typename T>

LinkedList<T>* mergeSortNew(LinkedList<T>* a) {
	if ((*a).size() == 1) return a;
	LinkedList<T>* left = new LinkedList<T>;
	LinkedList<T>* right = new LinkedList<T>;
	Node<T>* curr = (*a).head;
	for (int i = 1; i <= (*a).size() / 2; ++i) {
		(*left).addBack(curr->value);
		curr = curr->rightptr;
	}
	for (int i = (*a).size() / 2 + 1; i <= (*a).size(); ++i) {
		(*right).addBack(curr->value);
		if (curr->rightptr != nullptr) curr = curr->rightptr;
	}

	LinkedList<T>* leftMerge;
	LinkedList<T>* rightMerge;
	leftMerge = mergeSortNew(left);
	rightMerge = mergeSortNew(right);

	Node<T>* leftCurr = (*leftMerge).getHead();

	Node<T>* rightCurr = (*rightMerge).getHead();

	LinkedList<T>* ans = new LinkedList<T>;

	while (leftCurr != nullptr && rightCurr != nullptr) {
		if (leftCurr->value > rightCurr->value) {
			(*ans).addBack(leftCurr->value);
			leftCurr = leftCurr->rightptr;
		}
		else {
			(*ans).addBack(rightCurr->value);
			rightCurr = rightCurr->rightptr;
		}
	}
	if (leftCurr == nullptr) {
		while (rightCurr != nullptr) {
			(*ans).addBack(rightCurr->value);
			rightCurr = rightCurr->rightptr;
		}
	}
	if (rightCurr == nullptr) {
		while (leftCurr != nullptr) {
			(*ans).addBack(leftCurr->value);
			leftCurr = leftCurr->rightptr;
		}
	}

	return ans;
}


#endif	// ! LINKEDLIST#pragma once