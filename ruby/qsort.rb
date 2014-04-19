def quicksort(array)
  return array if array.size < 2

  pivot = array[((rand * 1000) % array.size).to_i]
  greater, less = Array.new, Array.new

  array.each do |element|
    partition = element > pivot ? greater : less
    partition << element
  end

  quicksort(less) + quicksort(greater)
end

print quicksort([5,6,1,2,54,9,7])
