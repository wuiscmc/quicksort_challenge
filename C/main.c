#include <stdio.h>
#include "qsort.h"


void print_array(int* array, int length){
  int i;
  for(i = 0; i < length; i++){
    printf("%d - ", array[i]);
  }
  printf("\n");
}


int main(){

  int array[6] = {8,7,2,2,6,1};

  print_array(quicksort(array, 6), 6);

  return 0;
}
