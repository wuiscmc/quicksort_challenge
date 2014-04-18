#include <stdlib.h>
#include <stdio.h>
#include "qsort.h"
#include <time.h>


void print_array(int* array, int length){
  int i;
  for(i = 0; i < length; i++){
    printf("%d - ", array[i]);
  }
  printf("\n");
}


int main(){

  srand(time(NULL));

  int array[6] = {8,7,2,2,6,8};

  print_array(quicksort(array, 6), 6);

  return 0;
}
