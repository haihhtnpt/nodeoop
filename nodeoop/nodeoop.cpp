// nodeoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	int data;
	Node* next;
public:
	
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	int  getData() {
		return data;
	}

    Node * getNext() {
		return next;
	}
	void setData(int data) {
		this->data=data;
	}
	void setNext(Node * tmp) {
		this->next = tmp;
		
	}

};
typedef class Node* node;
class List {
private:
	Node * pHead;
	Node * pTail;
public:
	List()
    {
		pHead = NULL;
		pTail = NULL;
	}
	void addHead(int data) {
		Node * tmp = new Node(data);
		if (pHead == NULL) {
			pHead = pTail = tmp;
			return;
		}
		else {
			
			tmp->setNext(pHead);
			pHead = tmp;
		}


	}
	void addLast(int data) {
		Node* tmp = new Node(data);
		if (pHead == NULL) {
			pHead = pTail = tmp;
			return;
		}
		else{
			pTail->setNext(tmp);
			pTail=tmp;

		}
	}
	void addMid(List &l,int  data, int pos) {
		int n = l.getLength(l);
		if (pos <= 0 || pos > n + 1)
			return;
		node tmp = new Node(data);
		if (pHead == NULL) {
			pHead = pTail = tmp;
			return;
		}
		else {
			if (n == 1) {
				l.addHead(data);
				return;
			}
			else if (n == pos + 1) {
				l.addLast(data);
				return;
			}
			node p = l.pHead;
			for (int i = 1; i < pos - 1; i++) {
				p = p->getNext();
			}
			tmp->setNext(p->getNext());
			p->setNext(tmp);

		}
		
	}
	
	int getLength(List l) {
		Node* tmp = pHead;
		int cnt = 0;
		while (tmp != NULL) {
			tmp = tmp->getNext();
			cnt++;
		}
		return cnt;
	}
	void exportList() {
		
		for (Node *p = pHead; p != NULL; p = p->getNext()) {
			cout << p->getData() << " ";
		}
	}
	void reverseList(List &l) {
		node before = NULL;
		node after = NULL;
		node current = l.pHead;
		while (current != NULL) {
			after = current->getNext();
			current->setNext(before);
			before = current;
			current = after;
		}
		l.pHead = before;

	}
	void delPos(List& l,int pos) {
		node tmp = l.pHead;
		if (pos <= 0 || pos > l.getLength(l)) {
			return;
		}
		else {
			node before = NULL;
			node after = l.pHead;
			for (int i = 1; i < pos;i++) {
				before = after;
				after = after->getNext();
			}
			if (before == NULL) {
				l.pHead = l.pHead->getNext();
			}
			else {
				before->setNext(after->getNext()) ;
				//before->getNext() = after->getNext();
			}
		}
		

	}
	void delDup(List& l) {
		node p1;
		node p2;
		node dup;
		p1 = l.pHead;
		if (p1 == NULL) {
			return ;
		}
		while (p1->getNext() != NULL) {
			p2 = p1;
			while (p2->getNext() != NULL) {
				if (p1->getData() == (p2->getNext()->getData())) {
					dup = p2->getNext();
					p2->setNext(p2->getNext()->getNext());
					delete(dup);
				}
				else {
					p2 = p2->getNext();
				}
				
			}
			p1 = p1->getNext();
		}
	}
	int findMid(List& l) {
		node p1, p2;
		p1 = l.pHead;
		p2 = l.pHead;
		if (p1 == NULL) {
			return 0;
		}
		while (p1->getNext() != NULL && p1->getNext()->getNext() != NULL) {
			p1 = p1->getNext()->getNext();
			p2 = p2->getNext();
		
		}
		return p2->getData();
	}
};


int main() {
	List l;
	l.addHead(1);
	l.addHead(2);
	l.addHead(3);
	l.addHead(3);
	l.addLast(4);
	l.addLast(4);
	l.addLast(5);
	cout << "do dai phan tu:= " <<l.getLength(l)<<endl;
//	l.delPos(l, 3);
	//l.delDup(l);

	//l.reverseList(l);
	//l.addMid(l, 6, 4);
	cout << "cac phan tu la:= ";
	l.exportList();
	cout << endl;
	int n= l.findMid(l);
	cout << n << endl;

	system("pause");


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
