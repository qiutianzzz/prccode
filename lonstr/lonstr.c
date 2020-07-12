#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int lengthCount ( char *s ){
    int cnt = 0;
    char temp;
    temp = *s;
    while('\0' != temp){
        cnt++;
        temp = *(s+1);
    }
    return cnt;
}


static int lengthOfLongestSubstring(char * s){
    int strLen = 0;
    int result = 0;
    int tlen = 0;
    strLen = lengthCount(s);
    char p;
    char *temp,  *head;
    head = s;
    
    p = *head;
    tlen = 0;
    do{
        tlen++;
        p = *(head + tlen);
        for (int i=0; i <= tlen; i++){
            if (p != *(head +i)){
                if (result < tlen){
                    result = tlen;
                    printf (" the temp result: %d\n", result);
                }
            }
            else{
                temp = head + i;
                head = temp;
                p = *head;
                tlen = 0;
                printf("break the loop \n");
                break;
            }
        } 
    }while('\0' != p)
    return result;
}

int main(){
    char a[] = {'a', 'b', 'c', 'd', 'e', 'a', 'f', 'g', 'h', '\0'};
    int len;
    len =  lengthOfLongestSubstring(a);
    printf("the substr length is: %d \n", len);
} 