//JS function-quick sort


function quickSort(array, left, right) {
    var i;
    
      if (array.length <=1) {
        return array; 
      } else {
        i = partition(array, left, right);
        if (left < i - 1) { 
            quickSort(array, left, i - 1);
        }
        if (i < right) { 
            quickSort(array, i, right);
        }
    }
    return array;
}
