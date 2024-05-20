#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int queue[256];
int count = 0;

void insertIntoQueue(int x){
    if(count == 256){
        fprintf(stderr, "No more space in the queue\n");
        return;
    }
    queue[count] = x;
    count ++;
}

int removeFromQueue(){
    if (count == 0){
        fprintf(stderr, "No elements");
        return -1;
    }
    int res = queue[0];
    int i=0;
    for (i=0; i < count -1; i++){
        queue[i]  = queue[i+1];
    }
    count --;
    
    return res;
    
}




int main(int argc, char* argv[]){
    insertIntoQueue(1);
    insertIntoQueue(2);
    insertIntoQueue(3);
    insertIntoQueue(4);
    
    int i;
    int localCount = count;
    for (i=0; i< localCount; i++){
        printf("%d ", removeFromQueue());
    }

    return 0;
}