#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s;
typedef struct Node{
    int key;
    struct Node * next;
} Node;


Node * initNodeList (int num, int* keys, Node *head){
    
    Node *temp, *pNode;
    temp = (Node *)malloc( sizeof(Node));
    head->next = NULL;
    pNode = head;
    
    for (int i = 0; i < num; i++){
        temp = (Node *)malloc( sizeof(Node));    
        temp->key = *(keys+i);
        // printf("############  %d ###############\n", temp->key);
        temp->next = NULL;
        pNode->next = temp;
        pNode = pNode->next;
    }
    // printf("############  ###############\n");
    return head;
}

int* stringToarray(){
    int i = 0;
    int num = 0;
    int *retarr;
    // int nums[num];
    
    int s; 
    int ret;    
    
    do
    {
        if (i == 0){
            ret = scanf("%d",&s);
            num = s;
            retarr = (int *)malloc((num+1) * sizeof(int));
            printf("############ nubber %d #############\n", num);
        }
        else{
            ret = scanf("%d",&s);
            *(retarr+(i-1)) = s;
        }
        i = i + 1;
        printf("### %d  %d ###\n", *(retarr+i), s);
    }while( i< (num+2) );
    // retarr = nums;
    return retarr;
}

int findKNode( Node* head, int listnum, int k){
    Node * temp;
    temp = head;
    for (int i=0; i <= (listnum -k); i++){
        temp = temp->next;
    }
    return temp->key;
}

int main(){
    
    int *numlist=(int *)malloc(sizeof(int));
    int res_key;
    Node * head =(Node*)malloc(sizeof(Node));

    // int num;
    // ret = scanf("%d", &num);
    numlist = stringToarray();
    
    head = initNodeList(num, numlist, head);

    
    res_key = findKNode ( head, num, *(numlist+num-1));
    printf("%d\n", res_key);
}















