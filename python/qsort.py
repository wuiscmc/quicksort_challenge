import random

def quicksort(array):
  if(len(array) < 2):
    return array
  else:
    pivot = array.pop(get_pivot(array))
    less = []
    greater = []
    for x in array:
      if(x <= pivot):
        less.append(x)
      else:
        greater.append(x)

    qsort_less = quicksort(less)
    qsort_less.extend([pivot])
    qsort_less.extend(quicksort(greater))
    return qsort_less

def get_pivot(array):
  return random.randrange(0, len(array))



print quicksort([5,2,1,12,3,5,61,8])
