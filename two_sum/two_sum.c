#include <stdio.h>
#include <stdlib.h>


int *twosum ( int* num, int numSize, int target, int *result )
{
    
    int ret[] = {0, 0};
    
    for (int i = 0; i < numSize; i++)
    {
        for (int j = i; j < numSize; j++)
        {
            if ( *(num+i) == target - *(num+j))
            {
                ret[0] = i;
                ret[1] = j;
                result = (int*)ret;
                printf("%d, %d, %d, %ld \n", target, i, j, sizeof(ret) );
                printf("%d, %d, %d, %d \n", ret[0], ret[1], *result, *(result+1) );
                return result;
            }
        }
    }
}
int main(void)
{
    int nums[] = { 3, 2, 4, 6, 5, 7 };
    int size = sizeof(nums) / sizeof(*nums);
    int target = 9;
    int *result;
    result = twosum( nums, size, target, result);
    printf(" %d, %d \n", result[0], result[1] );

    return 0;
}
