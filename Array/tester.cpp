#include "tester.hpp"

static inline void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

// Sort an array of integers
// arg1 - pointer to array
// arg2 - size of array
// arg3 - type of order: ASC or DESC
void test_sort(int *a, unsigned long s, int o) {
  unsigned long i, j, min_idx;   
    for (i = 0; i < s-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < s; j++) 
        if (o == 0) {
          if (a[j] < a[min_idx])  
            min_idx = j;  
        } else {
          if (a[j] > a[min_idx])  
            min_idx = j; 
        }
        
        swap(&a[min_idx], &a[i]);  
    }  
}

// Reverse an array of integers
// arg1 - pointer to array
// arg2 - size of array
void test_reverse(int *a, unsigned long s) {
  for (unsigned long i = 0; i < s / 2; i++) {
    swap(&a[i], &a[s - 1 - i]);
  }
}