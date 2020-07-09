#include <stdio.h>
#include <stdlib.h>
#include "math.h"

typedef struct list
{
    int val;
    struct list * next;
} LIST;




int countSize (LIST *k, int cnt)
{
    
    if ((LIST*)NULL == *(&k->next))
    {
        return(cnt+1);    
    }
    else
    {
        cnt = cnt+1;
        return countSize(k->next, cnt);
    }
}


int listToNum (LIST *k)
{
    int cnt = 0;
    int number = 0;
    int fa = 1;
    cnt = countSize(k, cnt);
    int num[cnt];
    printf("list size is: %d\n", cnt);
    LIST * t = k;
    LIST * temp;
    for(int i = 0; i < cnt; i=i+1)
    {
        if (NULL == (t->next))
        {num[i] = *(&t->val);}
        else
        {
            num[i] = (int)*(&t->val);
            temp = t;
            t = temp->next;
        }
        fa = fa * 10; 
        number = number + num[i] * fa /10; 
        
        printf("number is %d, %d\n", i, number);
    }
    return number;
}


int main(void)
{
    LIST a4 = {(int)3, (LIST*)NULL};
    LIST a3 = {(int)4, &a4};
    LIST a2 = {(int)8, &a3};
    LIST a1 = {(int)9, &a2};

    LIST b3 = {(int)5, (LIST*)NULL};
    LIST b2 = {(int)6, &b3};
    LIST b1 = {(int)7, &b2};

    int sum, a, b;
    a = listToNum(&a1);
    b = listToNum(&b1);
    sum = a + b;
    printf ("%d, %d, %d\n", a, b, sum);
    return 0;
}
