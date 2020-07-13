#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int lengthCount ( char *s ){
    int cnt = 0;
    char temp;
    temp = *s;
    while('\0' != temp){
        cnt++;
        temp = *(s + cnt);
    }
    return cnt;
}


static int lengthOfLongestSubstring(char * s){
    int strLen = 0;
    int result = 0;
    int tlen = 0;
    strLen = lengthCount(s);
    // printf ("a string length is: %d\n", strLen);
    char p;
    char *temp,  *head;
    head = s;
    
    p = *head;
    tlen = 0;
    do{
        tlen++;
        p = *(head + tlen);
        printf ("P char %c and tlen %d \n", p, tlen);
        for(int i = 0; i < tlen; i++){
            if (p != *(head + i)){
                printf ("----compare point %c, compare times: %d \n", *(head+i), (i+1));
                if (i == (tlen-1) && (result < tlen)){
                    result = tlen;
                    printf ("++++the temp result: %d\n", result);
                }
            }
            else{
                temp = head + i + 1;
                head = temp;
                p = *head;
                tlen = 0;
                printf("######the new head char: %c ######\n", p);
                break;                
            }
        }
    }while('\0' != p);
    return result;
}

int main(){
    char a[10] = {'a', 'b', 'c', 'd', 'e', 'a', 'c', 'g', 'h', '\0'};
    // printf ("a string is: %s\n", a);
    int len;
    len =  lengthOfLongestSubstring(a);
    printf("the substr length is: %d \n", len);
} 












