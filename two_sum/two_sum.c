#include <stdio.h>
#include <stdlib.h>

// struct object {
//     int val;
//     int index;
// };

// static int compare(const void *a, const void *b)
// {
//     return ((struct object *) a)->val - ((struct object *) b)->val;
// }

// static int * twosum(int *nums, int numsSize, int target, int *returnSize)
// {
//     int i, j;
//     struct object *objs = malloc(numsSize * sizeof(*objs));
//     for (i = 0; i < numsSize; i++) {
//         objs[i].val = nums[i];
//         objs[i].index = i;
//     }
//     qsort(objs, numsSize, sizeof(*objs), compare);
    
//     int *results = malloc(2 * sizeof(int));
//     i = 0;
//     j = numsSize - 1;
//     while (i < j) {
//         int sum = objs[i].val + objs[j].val;
//         if (sum < target) {
//             i++;
//         } else if (sum > target) {
//             j--;
//         } else {
//             results[0] = objs[i].index;
//             results[1] = objs[j].index;
//             *returnSize = 2;
//             return results;
//         }
//     }
//     return NULL;
// }

static int *twosum (void* num, int target, int *result )
{
    int numSize = sizeof(*num);
    int nums[numSize];
    result = malloc(2 * sizeof (int));
    for (int i = 0; i < numSize; i++)
    {
        for (int j = i; j < numSize; j++)
        {
            if (nums[i] == target - nums[j])
            {
                *result = (i, j);
                printf("%d, %d, %d \n", target, i, j );
                return result;
            }
        }
    }
}
int main(void)
{
    int nums[] = { 3, 2, 3, 6, 5, 7 };
    // int size = sizeof(nums) / sizeof(*nums);
    int target = 8;
    int * result;
    twosum( &nums, target, result);
    printf(" %d, %d \n", result[0], result[1] );
    // int *indexes = twosum(nums, size, target, &count);
    // if (indexes != NULL) {
    //     printf("%d %d\n", indexes[0], indexes[1]);
    // } else {
    //     printf("Not found\n");
    // }

    return 0;
}
