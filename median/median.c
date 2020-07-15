#include <stdio.h>
#include <stdlib.h>



int main (){
    int A[] = {1, 2, 3, 5, 6, 8};
    int B[] = {9, 12, 14, 16};
    int i, j = 0;

    int sizeA = sizeof(A);
    int sizeB = sizeof(B);

}


// Set imin=0, imax=m, then start searching in [imin,imax]

// Set i = (imin+imax)/2    j = (m + n + 1)/2 - i 
// Now we have \text{len}(\text{left}\_\text{part})=\text{len}(\text{right}\_\text{part})len(left_part)=len(right_part). And there are only 3 situations that we may encounter:

// B[j−1]≤A[i] and A[i−1]≤B[j]
// Means we have found the object ii, so stop searching.

// B[j−1]>A[i]
// Can we increase i?
//       Yes. Because when ii is increased, jj will be decreased.
//       So, set imax=i+1, and goto 2.

// A[i−1]>B[j]:
// Means A[i−1] is too big. And we must decrease i to get A[i−1]≤B[j].
// That is, we must adjust the searching range to [imin,i−1].
// So, set imax=i−1, and goto 2.
int median(int* A, int *B, int m, int n){
    int temp = 0;
    int *ptemp = NULL;
    if (m > n){
        temp = m;
        m = n;
        n = temp;
        ptemp = A;
        A = B;
        B = temp;
    }

    int imin = 0; 
    int imax = m; 
    int i = 0;
    int j = 0;

    while (imin <= imax){
        i = 
    }
}