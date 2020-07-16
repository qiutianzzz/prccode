#include <stdio.h>
#include <stdlib.h>





// Set imin=0, imax=m, then start searching in [imin,imax]

// Set i = (imin+imax)/2    j = (m + n + 1)/2 - i 
// Now we have \text{len}(\text{left}\_\text{part})=\text{len}(\text{right}\_\text{part})len(left_part)=len(right_part). And there are only 3 situations that we may encounter:

// B[j−1]≤A[i] and A[i−1]≤B[j]
// Means we have found the object ii, so stop searching.

// B[j−1]>A[i]
// Can we increase i?
//       Yes. Because when ii is increased, jj will be decreased.
//       So, set imin=i+1, and goto 2.

// A[i−1]>B[j]:
// Means A[i−1] is too big. And we must decrease i to get A[i−1]≤B[j].
// That is, we must adjust the searching range to [imin,i−1].
// So, set imax=i−1, and goto 2.
int median(int* A, int *B, int m, int n){
    int temp = 0;
    int *ptemp = NULL;
    int result = 0;
    if (m > n){
        temp = m;
        m = n;
        n = temp;
        ptemp = A;
        A = B;
        B = ptemp;
    }

    int imin = 0; 
    int imax = m; 
    int i = 0;
    int j = 0;
    int max_left = 0;
    int min_right = 0;

    while (imin <= imax){
        i = (imin + imax)/2;
        j = (m + n +1)/2 - i;   
        if ((*(B+j-1) > *(A+i)) && (i < m)){
            imin = i + 1;
        }
        else if((*(B+j) < *(A+i-1)) && (i > 0)){
            imax = i - 1;
        }
        else{ //perfect
            if (i == 0){ max_left = *(B+j-1);}
            else if (j == 0) {max_left = *(A+i-1);}
            else{//normal left
                if (*(A+i-1) >= *(B+j-1)){max_left = *(A+i-1);}
                else{max_left = *(B+j-1);}
                printf("max left is %d \n", max_left);
            } //normal left

            if ((m+n)%2 == 1){ return max_left;}
            if (i==m){min_right = *(B+j);}
            else if (j == n){min_right = *(A+i); }
            else{ //normal right
                if (*(A+i) <= *(B+j)){ min_right = *(A+i);}
                else{min_right = *(B+j);}
                printf("min right is %d \n", min_right);
            }//normal right
            return ((max_left + min_right)/2);
        } //perfect
    }//while
       
}//median

int main (){
    int A[] = {1, 2, 3, 5, 6, 8};
    int B[] = {9, 12, 14, 16};

    int sizeA = sizeof(A);
    int sizeB = sizeof(B);
    int result = 0;

    result = median(A, B, sizeA, sizeB);
    printf("the median result is: %d\n", result);

}




























