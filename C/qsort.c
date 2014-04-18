#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"

int* merge(int* array1, int array1_length, int* array2, int array2_length) {

  int* array_merged = (int*) malloc(sizeof(int) * (array1_length + array2_length));

  int i;
  for(i = 0; i < array1_length; i++) {
    array_merged[i] = array1[i];
  }

  int j = i;
  for(i = 0; i < array2_length; i++) {
    array_merged[j] = array2[i];
    j++;
  }

  return array_merged;
}

int select_pivot(int* array, int length) {
  int i = rand() % length;
  return array[i];
}


int* copy_array(int* array, int length) {
  int* array_copy = (int*) malloc(length * sizeof(int));
  int i;
  for(i = 0; i < length; i++) {
    array_copy[i] = array[i];
  }
  return array_copy;
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
