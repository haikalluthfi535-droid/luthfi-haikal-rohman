#include <iostream>
#include <cstddef>

struct Node {
    int INFO;
    Node* LINK;
};

int main() {
    Node* FIRST = NULL;
    Node* LAST = NULL;
    Node* Q = NULL;

    int values[] = {1, 4, 10, 20, 30, 40, 80, 90, 5, 50, 60, 7};
    int n = sizeof(values) / sizeof(values[0]);

    if (n > 0) {
        FIRST = new Node();
        FIRST->INFO = values[0];
        FIRST->LINK = NULL;
        LAST = FIRST;

        for (int i = 1; i < n; i++) {
            Node* newNode = new Node();
            newNode->INFO = values[i];
            newNode->LINK = NULL;
            LAST->LINK = newNode;
            LAST = newNode;
        }
    }

    std::cout << "--- Hasil Penugasan Pointer Q ---" << std::endl;

    Q = FIRST;
    std::cout << "a. Q menunjuk simpul no (1): ";
    if (Q != NULL) std::cout << Q->INFO << std::endl;
    else std::cout << "NULL" << std::endl;

    Node* P_b = FIRST;
    for (int i = 1; i < 7 && P_b != NULL; i++) {
        P_b = P_b->LINK;
    }
    Q = P_b;
    std::cout << "b. Q menunjuk simpul no (7): ";
    if (Q != NULL) std::cout << Q->INFO << std::endl;
    else std::cout << "NULL" << std::endl;

    Q = LAST;
    std::cout << "c. Q menunjuk simpul akhir: ";
    if (Q != NULL) std::cout << Q->INFO << std::endl;
    else std::cout << "NULL" << std::endl;

    Node* P_d = FIRST;
    while (P_d != NULL && P_d->INFO != 50) {
        P_d = P_d->LINK;
    }
    Q = P_d;
    std::cout << "d. Q menunjuk simpul dengan INFO = 50: ";
    if (Q != NULL) std::cout << Q->INFO << std::endl;
    else std::cout << "NULL" << std::endl;

    Node* P_e = FIRST;
    Node* PREV_e = NULL;
    bool found_e = false;
    while (P_e != NULL) {
        if (P_e->INFO == 50) {
            found_e = true;
            break;
        }
        PREV_e = P_e;
        P_e = P_e->LINK;
    }
    
    if (found_e) {
        Q = PREV_e;
    } else {
        Q = NULL;
    }
    std::cout << "e. Q menunjuk simpul sebelum INFO = 50: ";
    if (Q != NULL) std::cout << Q->INFO << std::endl;
    else std::cout << "NULL" << std::endl;

    Node* temp = FIRST;
    while (temp != NULL) {
        Node* next = temp->LINK;
        delete temp;
        temp = next;
    }

    return 0;
}
