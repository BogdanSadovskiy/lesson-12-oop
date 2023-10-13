using namespace std;
#include <iostream>
class Node {
public:
    int date;
    Node* pre;
    Node* next;
    Node() { date = 0; pre = nullptr; next = nullptr; }
    Node(int date) { this->date = date; pre = nullptr; next = nullptr;}
};
void add(Node*& list, int date) {
    Node* n = new Node(date);
    if (list == nullptr) {
        list = n;
        return;
    }
    Node* tmp = list;
    Node* preNode = nullptr;
  
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }

    tmp->next = n;
    preNode = tmp;
    tmp->next->pre = preNode;
}
void display(Node* list) {
    Node* tmp = list;
    cout << "From L to R:\n";
    while (tmp->next != nullptr) {
        cout << tmp->date << " ";
        tmp = tmp->next;
    }
    cout << tmp->date;
    cout << endl;
    
    cout << "From R to L:\n";
    while (tmp != nullptr) {
        cout << tmp->date << " ";
        tmp = tmp->pre;
    }
    cout << endl;
}
int main()
{
    Node* list = nullptr;
    cout << "Input numbers:\n";
    int date;
    do {
        cin >> date;
        if (date != 0) {
            add(list, date);
        }
    } while (date != 0);

    display(list);

}

