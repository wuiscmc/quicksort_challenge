(function(){

  Quicksort = function(){

  };

  Quicksort.prototype.sort = function(array) {
    if (array.length < 2) {
      return array;
    }

    var greater = [];
    var less = [];
    var pivot = get_pivot(array);

    for(var i = 0; i < array.length; i++ ){
      if (array[i] < pivot) {
        less.push(array[i]);
      }
      else {
        greater.push(array[i]);
      }
    }

    return merge(this.sort(less), this.sort(greater));
  };

  var merge = function(array1, array2) {
    return array1.concat(array2);
  };

  var get_pivot = function(array) {
    return array[parseInt((Math.random() * 100) % array.length)];
  };

})();
