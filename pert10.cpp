#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// fungsi push untuk menambahkan elemen ke stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// fungsi pop untuk menghapus elemen teratas
void pop() {
    if (top == NULL) {
        printf("Stack kosong\n");
    } else {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

// fungsi untuk menampilkan elemen stack
void display() {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// fungsi untuk menampilkan elemen top
void peek() {
    if (top == NULL)
        printf("Stack kosong\n");
    else
        printf("Elemen Top adalah %d\n", top->data);
}

int main() {
    push(11);
    push(22);
    push(33);
    push(44);
    display();
    peek();
    pop();
    pop();
    display();
    peek();
    return 0;
}
