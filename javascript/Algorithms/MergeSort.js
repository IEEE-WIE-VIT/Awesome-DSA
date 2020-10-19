
function mergeSort(left, right) 
{
  var final = [];
	var i = 0;
	var j = 0;
  var r= right.length;
  var l= left.length;
	
	while (j < r || i < l) {
		if (i === l) {
			final.push(right[j]);
			j++;
		} 
      else if (j === r || left[i] <= right[j]) {
			final.push(left[i]);
			i++;
		} else {
			final.push(right[j]);
			j++;
		}
	}
  
	return final;
}

//console.log(mergeSort([6,2,7], [1,8,0]));
//[0,1,2,5,6,8]
