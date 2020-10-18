 function swap(array, index){
    var temp = array[index];
    array[index] = array[index + 1];
    array[index +1 ] = temp;
}

function bubbleSort(array){

    var len = array.length,
        i, j, n;

    for (i=0; i < len; i++){
        for (j=0, n=len-i; j < n; j++){
            if (array[j] > array[j+1]){
                swap(array, j);
            }
        }
    }

    return array;
}
//console.log(bubbleSort([9,1,8,3,7,2,5,4,-3]));
// [-3,1,2,3,4,5,7,8,9]
