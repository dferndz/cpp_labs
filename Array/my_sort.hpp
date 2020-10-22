// Type of sort flag
// ASC == 0
// DESC == 1
enum SORT_ORDER {ASC, DESC};

// Sort an array of integers
// arg1 - pointer to array
// arg2 - size of array
// arg3 - type of order: ASC or DESC
void my_sort(int *a, unsigned long s, SORT_ORDER o);