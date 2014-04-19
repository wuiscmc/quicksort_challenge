#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"

void copy_array_elements(int* input, int* output, int length) {
  int i;
  for(i = 0; i < length; i++) {
    output[i] = input[i];
  }
}

int* copy_array(int* array, int length) {
  int* array_copy = (int*) malloc(length * sizeof(int));
  copy_array_elements(array, array_copy, length);
  return array_copy;
}

int select_pivot(int* array, int length) {
  int i = rand() % length;
  return array[i];
}

int* merge(int* array1, int array1_length, int* array2, int array2_length) {

  if(array1 == NULL && array2 == NULL) {
    return NULL;
  }

  int* array_merged = (int*) malloc(sizeof(int) * (array1_length + array2_length));

  copy_array_elements(array1, array_merged, array1_length);
  copy_array_elements(array2, (array_merged + array1_length), array2_length);

  return array_merged;
}

int* quicksort(int* array, int length) {

  if((length < 2) || (length == 2 && array[0] == array[1])){
    return array;
  }

  int* __greater = (int*) malloc(length * sizeof(int));
  int* __less = (int*) malloc(length * sizeof(int));

  int i = 0, greater_length = 0, less_length = 0;
  int pivot = select_pivot(array, length);

  for(; i < length; i++) {
      if(array[i] < pivot) {
        __less[less_length] = array[i];
        less_length ++;
      }
      else {
        __greater[greater_length] = array[i];
        greater_length ++;
      }
  }

  int* greater = copy_array(__greater, greater_length);
  int* less = copy_array(__less, less_length);

  free(__greater);
  free(__less);

  int* less_sorted = quicksort(less, less_length);
  int* greater_sorted = quicksort(greater, greater_length);
  int* merged = merge(less_sorted, less_length, greater_sorted, greater_length);

  free(greater_sorted);
  free(less_sorted);

  return merged;
}
