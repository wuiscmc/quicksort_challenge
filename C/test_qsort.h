#ifndef TEST_QSORT_INCLUDED
#define TEST_QSORT_INCLUDED

#define TEST_MODE

  int* merge(int* array1, int array1_length, int* array2, int array2_length);

  int select_pivot(int* array, int length);

  int* copy_array(int* array, int length);

  int* quicksort(int* array, int length);

#endif //TEST_QSORT_INCLUDED
