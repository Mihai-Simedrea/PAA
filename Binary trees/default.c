#include <stdio.h>
#include <stdlib.h>

// Definim strctura de tip arbore
typedef struct tree_node {
    int value;  // valoarea de tip int
    struct tree_node *left;  // fiul din partea stanga
    struct tree_node *right;  // fiul din partea dreapta
} tree_node;


// Definim functia pentru a aloca un nod
tree_node* create_tree_node(int value) {
    // value: int - valoarea pe care o va avea nodul
    // return: tree_node* - returneaza pointer la nod

    tree_node* node = (tree_node*)malloc(sizeof(tree_node) * 1);  // alocam memorie pentru nod

    // verificam daca alocarea a avut loc cu succes
    if (node != NULL) {
        node->value = value;  // atribuim valoarea trimisa prin parametru

        // by default, fii din stanga si dreapta vor fi pe NULL, pentru ca noi alocam doar pentru un SINGUR nod, ci anume, nodul parinte
        node->left = NULL; 
        node->right = NULL;
    }
    
    return node;
}

// Definim functia pentru a parcurge in preordine (RSD)
void print_preorder(tree_node* root) {
    // daca radacina e nula, inseamna ca nodul nu exista, deci iesim din recursivitate
    if (root == NULL) {
        return;
    }

    // altfel, radacina nu e nula, putem sa o printam

    printf("%d ", root->value);

    // din moment ce nu e nula, noi cum vrem sa parcurgem arborele?
    // acum suntem la RADACINA, deci, vom merge mai intai in partea stanga

    print_preorder(root->left);

    // apoi, dupa ce revenim din prima recursivitate, intram in a doua
    // si vom merge in nodul din dreapta

    print_preorder(root->right);
}

int main(void) {
    // Cream 5 noduri pentru test
    tree_node* n1 = create_tree_node(1);
    tree_node* n2 = create_tree_node(2);
    tree_node* n3 = create_tree_node(3);
    tree_node* n4 = create_tree_node(4);
    tree_node* n5 = create_tree_node(5);

    // acum, nodurile nu sunt legate intre ele, sunt doar alocate in HEAP si that's all

    // sa zicem ca vrem urmatoarea legatura
    /*
    
        n1 - stanga: n2, dreapta: n3
        n3 - stanga: n4, dreapta: n5

        va arata ceva de genul

                n1
                /\
               /  \
             n2    n3
                   /\
                  /  \
                n4    n5

        e un arbore binar cu radacina: n1
    
    */

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    // acum ca am legat nodurile, trebuie sa le parcurgem
    // sunt mai multe tipuri de parcurgere, hai sa parcurgem in PREORDINE, adica: incepem cu radacina, dupa mergem la fiul din stanga dupa dreapta

    print_preorder(n1);

    return 0;
}