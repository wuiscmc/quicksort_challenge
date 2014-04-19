#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "test_qsort.h"

void print_array(int* array, int length){
  int i;
  for(i = 0; i < length; i++){
    printf("%d - ", *(array + i));
  }
  printf("\n");
}

int contains_element(int element, int* array, int length) {
  int contained = 0;
  int i = 0;
  for(; i < length; i++) {
    if(*(array + i) == element){
      contained = 1;
      break;
    }
  }
  return contained;
}

/*
  I wanted to experiment on passing by reference in arrays...
  another aproach for this function would be to return the new
  array without the element. However, this approach has the advantage
  of having fewer memory leaks.
*/
int remove_element(int element, int **array, int length) {
  int i = 0;
  if (contains_element(element, *array, length)) {
    int removed = 0;
    int* new_array = (int*) malloc(sizeof(int) * (length - 1));
    int j = 0;
    int current_element;
    for(i = 0; i < length; i++) {
      current_element = *(*array + i);
      if (element == current_element && !removed) {
        removed = 1;
      }
      else {
        new_array[j] = current_element;
        j++;
      }
    }
    if(removed) {
      free(*array);
      *array = new_array;
      return 1;
    }
    else {
      print_array(*array, length);
      return 0;
    }
  }
  else {
    return 0;
  }

}


static void test_select_pivot(){
  int array[2] = {5,4};
  int pivot = select_pivot(array, 2);
  assert(pivot == 5 || pivot == 4);
}

static void test_merge_arrays(){
  int array1[2] = {5,4}; int array1_length = 2;
  int array2[3] = {1,2,3}; int array2_length = 3;
  int* array_merged = merge(array1, array1_length, array2, array2_length);
  int equals = 0x1;

  int i = 0;
  for(i = 0; i < array1_length; i++){
    if (array_merged[i] != array1[i]){
      equals = 0x0;
    }
  }

  int j = i;
  for(i = 0; i < array2_length; i++){
    if (array_merged[j] != array2[i]){
      equals = 0x0;
    }
    j++;
  }

  int array_merged_length = j;
  free(array_merged);

  assert(equals == 0x1);
  assert(array_merged_length == (array1_length + array2_length));
}

static void test_merge_arrays_one_empty(){
  int array1[2] = {5,4};
  int array1_length = 2;
  int* array_merged = merge(array1, array1_length, NULL, 0);
  int equals = 0x1;
  int i = 0;

  while(i < array1_length && equals == 0x1){
    if (array_merged[i] != array1[i]) {
      equals = 0x0;
    }
    i++;
  }

  int array_merged_length = i;

  assert(array_merged != array1);
  free(array_merged);

  assert(equals == 0x1);
  assert(array_merged_length == array1_length);
}

static void test_copy_array(){

  int array[3] = {1,2,3};
  int array_length = 3;
  int* array_copy = copy_array(array, array_length);
  int equals = 0x1;
  int i = 0;

  while(i < array_length && equals == 0x1){
    if (array_copy[i] != array[i]) {
      equals = 0x0;
    }
    i++;
  }

  int array_copy_length = i;

  assert(array_copy != array);
  free(array_copy);

  assert(equals == 0x1);
  assert(array_copy_length == array_length);
}


static void test_quicksort(){
  int array[4] = {2,9,1,5};
  int expected_sorted_array[4] = {1,2,5,9};
  int *array_sorted = quicksort(array, 4);
  int i = 0;
  int equals = 0x0;
  for(; i < 4; i ++){
    if (expected_sorted_array[i] != array_sorted[i])
    {
      equals = 0x1;
    }
  }

  assert(equals == 0x0);
}

/*
  Just for fun, wanted to try a crazy way of testing the equality
*/
static void test_quicksort_2(){
  int array[5] = {3,4,1,7,5};
  int array_length = 5;
  int* array_sorted = quicksort(array, array_length);

  int same_elements = 0x1;
  int i = 0;
  int array_sorted_length = array_length;

  for(; i < array_length; i++) {
    if (remove_element(array[i], &array_sorted, array_sorted_length)) {
      array_sorted_length --;
    }
    else {
      same_elements = 0x0;
    }
  }

  assert(same_elements == 0x1);
  assert(array_sorted_length == 0);
}



int main(){

  test_select_pivot();
  test_merge_arrays();
  test_merge_arrays_one_empty();
  test_copy_array();
  test_quicksort();
  test_quicksort_2();

  return 0;

}
