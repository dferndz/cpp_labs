// Type of sort flag
// ASC == 0
// DESC == 1
enum SORT_ORDER {ASC, DESC};

// Sort an array of integers
// arg1 - pointer to array
// arg2 - size of array
// arg3 - type of order: ASC or DESC
void my_sort(int *a, unsigned long s, SORT_ORDER o);

// Reverse an array of integers
// arg1 - pointer to array
// arg2 - size of array
void reverse(int *a, unsigned long s);

// search an array of integers
// arg1 - pointer to array
// arg2 - size of array
unsigned long search(int *a, unsigned long s, int target);

// Binary search an array of integers
//    You may assume the array will be sorted asc
// arg1 - pointer to array
// arg2 - size of array
unsigned long binary_search(int *a, unsigned long s, int target);