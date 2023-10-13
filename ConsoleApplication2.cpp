#define task3
#define fortask2
#include <iostream>
using namespace std;
#ifdef fortask1
class Node
{
public:
	string date;
	Node* ptr1;
	Node* ptr2;

	Node() { date = ""; ptr1 = nullptr; ptr2 = nullptr; }
	Node(string date) { this->date = date; ptr1 = nullptr; ptr2 = nullptr; }
};
#endif 

#ifdef fortask2
class Node {
public:
	int date;
	Node* next;
	Node() { date = 0; next = nullptr; }
	Node(int date) { this->date = date; next = nullptr; }
};
void AddTail(Node*& head, int date) {
	Node* n = new Node(date);
	if (head == nullptr) {
		head = n;
		return;
	}

	Node* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = new Node(date);
}

void display(Node* head) {
	Node* tmp = new Node();
	tmp = head;
	while (tmp != nullptr) {
		cout << tmp->date << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
int amountMinus(Node* head) {
	Node* tmp = head;
	int k = 0;
	while (tmp != nullptr) {
		if (tmp->date < 0) {
			k++;
		}
		tmp = tmp->next;
	}
	return k;
}
void addToNum(Node*& head, int date) {
	Node* tmp = head;
	while (tmp != nullptr) {
		tmp->date = tmp->date + date;
		tmp = tmp->next;
	}
}
bool deleteNum(Node*& head, int date) {
	Node* tmp = head;
	if (tmp->date == date) {
		if (tmp->next != nullptr) {
			tmp = tmp->next;
			head = tmp;
			return true;
		}
		tmp = nullptr;
		return false;
	}
	
	while (tmp->next != nullptr) {
		if (tmp->next->date == date) {
			if (tmp->next->next != nullptr) {
				tmp->next = tmp->next->next;
				return true;
			}
			tmp->next = nullptr;
			return false;
		}
		tmp = tmp->next;
	}
	return false;
}
void deleteNumbs(Node*& head, int date) {
	while (deleteNum(head, date));
}
bool addnum(Node*& head, int date, int secdate) {
	Node* tmp = head;
	int k = 0;
	while (tmp!=nullptr)  {
		if (tmp->date == date) {
			Node* n = new Node(secdate);
			n->next = tmp->next;
			tmp->next = n;
			k++;

		}
		tmp = tmp->next;
	}
	if (k > 0) { 
	   return true; 
	}
	cout << "Input existed numb\n";
	return false;
}
#endif  



int main()
{
#ifdef task 
	Node* head = new Node("first");
	head->ptr1 = new Node("second");//2in1
	head->ptr2 = new Node("fourth");//4in1
	//1 is ready
	head->ptr1->ptr1 = head;//1in2
	head->ptr1->ptr2 = new Node("third");//3in2
	//2 is ready
	head->ptr1->ptr2->ptr1 = head->ptr1; // 2in3
	head->ptr1->ptr2->ptr2 = head->ptr2;//4in3
	//3is ready
	head->ptr2->ptr1 = head->ptr1; // 2in4
	head->ptr2->ptr2 = nullptr;
	//4is ready

	cout << "1 " << head->date << endl;
	cout << "1in2 " << head->ptr1->ptr1->date << endl;
	cout << "2in1 " << head->ptr1->date << endl;
	cout << "2in3 " << head->ptr1->ptr2->ptr1->date << endl;
	cout << "2in4 " << head->ptr2->ptr1->date << endl;
	cout << "3in2 " << head->ptr1->ptr2->date << endl;
	cout << "4in1 " << head->ptr2->date << endl;
	cout << "4in3 " << head->ptr1->ptr2->ptr1->date << endl;
#endif
#ifdef task2
	Node* head = new Node("first");//first
	head->ptr1 = new Node("second");//2in1
	head->ptr2 = new Node("third"); //3in1
	//1 is ready
	head->ptr1->ptr1 = new Node("fourth"); // 4in2
	head->ptr1->ptr2 = head; // 1in2
	//2 is ready
	head->ptr2->ptr1 = head->ptr1; // 2in3
	head->ptr2->ptr2 = head->ptr1->ptr1; // 4in3
	//3 is ready
	head->ptr1->ptr1->ptr1 = head; // 1in4
	head->ptr1->ptr1->ptr2 = head->ptr1;//2in4

	cout << "Head " << head->date << endl;
	cout << "2 in1 " << head->ptr1->date << endl;
	cout << "3 in1 " << head->ptr2->date << endl;
	cout << "4 in2 " << head->ptr1->ptr1->date << endl;
	cout << "1 in2 " << head->ptr1->ptr2->date << endl;
	cout << "2 in3 " << head->ptr2->ptr1->date << endl;
	cout << "4 in3 " << head->ptr2->ptr2->date << endl;
	cout << "1 in4 " << head->ptr1->ptr1->ptr1->date << endl;
	cout << "2 in4 " << head->ptr1->ptr1->ptr2->date << endl;

#endif
#ifdef task3
	Node* list = nullptr;
	int date = 0;
	int k = 0;
	cout << "Input some numbers (input 0 to exit)\n";
	do {
		if (date != 0) {
			AddTail(list, date);
		}
		cout << ++k << " num - ";
		cin >> date;
		cout << endl;
	} while (date != 0);

	display(list);
	cout << "Amount of minus numbers - " << amountMinus(list) << endl;
	cout << "--------------------------------------------\n";

	cout << "Input number you want to plus for every number in the list\n";
	cin >> date;
	addToNum(list, date);
	display(list);

	cout << "Input number to delete \n";
	cin >> date;
	deleteNumbs(list, date);
	display(list);
	int secdate;
	do {
		cout << "Input list number - ";
		cin >> date;
		cout << "Input number - ";
		cin >> secdate;
	} while (!addnum(list, date, secdate));
	
	display(list);

#endif 

}
