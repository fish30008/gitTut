#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* next; 
}Node;

int main(){
    Node person;
    person.value = 10;
    person.next = malloc(sizeof(int));
    person.next->value = 200;
    person.next->next = malloc(sizeof(int));
    person.next->next->value = 300;
    person.next->next->next = NULL;


    Node* curr = &person;
    while(curr != NULL){
        printf("%d\n", curr -> value);
        curr = curr -> next;
    }

    

    free(person.next);
    free(person.next->next);
    return 0;
}