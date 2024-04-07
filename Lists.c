#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int value;
    struct Node* next; 
}Node;

void insert_end(Node** person, int x){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        exit(1);
    }
    new_node->next = NULL;
    new_node->value = x;

    if(*person == NULL){
        *person = new_node;
        return;
    }

    Node* curr = *person;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr -> next = new_node;

}


int main(){
  
    Node* person = NULL;
    // if (person == NULL){
    //     exit(2);
    // }
    
    
    // person->value=15;
    // (*person).next = NULL;
    srand(time(0));
    int n=0;
    
    
    
    for(int i=0; i<10; i++){
        n = (rand() % 
        (39 - 7 + 1)) + 7;
          insert_end(&person, n);
    }

    
    for(Node* curr = person; curr != NULL; curr = curr->next){
        printf("%d\n", curr->value);
    }
    

    
    return 0;
}