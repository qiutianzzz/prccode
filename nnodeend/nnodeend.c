#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct NODE * next;
} NODE;


static NODE * removeNendNode(NODE * head, int n){
    int length = 0;
    NODE *temp;
    NODE *p;
    p = head;

    while( head->next != NULL){
        length++;
    }
    if ( 0 == length){
        return head;
    }
    else{
        for (int i = 0; i < (length-n); i++){
            temp = p->next;
            p = temp;
        }
        temp = p->next->next;
        p->next->next = NULL;
        p->next = temp;
    }
    return head;
} 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    while(p){
        if(n < 0){ q = q -> next; }       
        n--;
        p = p -> next;
    }
    if(n == 0){ return head -> next; }
    q -> next = q -> next -> next;
    return head;
}


void InitList(NODE *L) //初始化
{
    L = malloc(sizeof(NODE));
    L->next = NULL;
}


int main(){

    NODE *n5;
    n5->val = 5;
    n5->next = NULL;
    NODE *n4;
    n4->val = 4;
    n4->next = n5;
    NODE n3;
    n3.val = 3;
    n3.next = &n4;
    NODE n2;
    n2.val = 2;
    n2.next = &n3;
    NODE n1;
    n1.val = 1;
    n1.next = &n2;

    NODE *result;
    
    result = removeNendNode (&n1, 2);
    printf("value of the new node: %d\n", n4.val);

}
