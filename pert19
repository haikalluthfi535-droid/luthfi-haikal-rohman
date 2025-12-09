#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;
Node* newNode(char c) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = c;
    n->left = n->right = NULL;
    return n;
}
void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}
int main() {
    Node *R = newNode('R');
    Node *A = newNode('A');
    Node *S = newNode('S');
    Node *I = newNode('I');
    Node *T = newNode('T');
    Node *E = newNode('E');
    R->left = A;
    R->right = E;
    A->left = S;
    S->left = I;
    S->right = T;
    printf("Tampilan secara PreOrder : ");
    preOrder(R);
    printf("\n");
    printf("Tampilan secara InOrder  : ");
    inOrder(R);
    printf("\n");
    printf("Tampilan secara PostOrder: ");
    postOrder(R);
    printf("\n");
    free(I); free(T); free(S); free(A); free(E); free(R);
    return 0;
}
