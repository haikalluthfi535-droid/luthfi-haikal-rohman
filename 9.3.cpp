#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->info = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int totalInfo() {
        int total = 0;
        Node* temp = head;
        while (temp != NULL) {
            total += temp->info;
            temp = temp->next;
        }
        return total;
    }

    void printAllInfo() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int countInfoEqual50() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->info == 50) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    list.insert(25);
    list.insert(12);
    list.insert(27);
    list.insert(14);

    cout << "Jumlah simpul: " << list.countNodes() << endl;
    cout << "Total INFO: " << list.totalInfo() << endl;
    cout << "Semua nilai INFO: ";
    list.printAllInfo();
    cout << "Jumlah simpul dengan INFO = 50: " << list.countInfoEqual50() << endl;

    return 0;
}
