#include <iostream>
#include <cstddef> // Untuk NULL

struct Node {
    int INFO;
    Node* LINK;
};

int main() {
    Node* P = new Node();
    Node* Q = new Node();
    Node* R = new Node();
    Node* S = new Node();

    P->INFO = 1;
    P->LINK = Q;

    Q->INFO = 4;
    Q->LINK = R;

    R->INFO = 5;
    R->LINK = S;

    S->INFO = 7;
    S->LINK = NULL; // Diganti dari nullptr

    std::cout << std::boolalpha;

    std::cout << "--- Hasil Evaluasi Kondisi (c) ---" << std::endl;

    std::cout << "i.   if(P->LINK == R)       : " << (P->LINK == R) << std::endl;
    std::cout << "ii.  if(Q->LINK == R->LINK) : " << (Q->LINK == R->LINK) << std::endl;
    std::cout << "iii. if(Q->LINK == S->LINK) : " << (Q->LINK == S->LINK) << std::endl;
    std::cout << "iv.  if(Q == R)             : " << (Q == R) << std::endl;
    std::cout << "v.   if(Q->LINK == R)       : " << (Q->LINK == R) << std::endl;
    
    // Perbaikan untuk vi: Perlu cek R->LINK tidak NULL sebelum akses INFO
    if (R->LINK != NULL) {
        std::cout << "vi.  if(R->LINK->INFO == 5) : " << (R->LINK->INFO == 5) << std::endl;
    } else {
        std::cout << "vi.  if(R->LINK->INFO == 5) : (error: R->LINK is NULL)" << std::endl;
    }
    
    std::cout << "vii. if(Q->INFO == 4)      : " << (Q->INFO == 4) << std::endl;

    delete P;
    delete Q;
    delete R;
    delete S;

    return 0;
}
