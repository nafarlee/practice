var reverseArray = function (array) {
	var reversed = [];
	for (var i = array.length-1; i >= 0; i--) {
		reversed.push(array[i]);
	}
	return reversed;
};

var reverseArrayInPlace = function (array) {
	var midpoint = Math.floor(array.length/2);

	for (var i = 0; i < midpoint; i++) {
		var temp = array[i];
		array[i] = array[array.length-1-i];
		array[array.length-1-i] = temp;

	}
};

console.log(reverseArray([1, 2, 3, 4, 5]));
console.log(reverseArray([1, 2, 3, 4]));

var array = [1, 2, 3, 4, 5];
reverseArrayInPlace(array);
console.log(array);

var array2 = [1, 2, 3, 4];
reverseArrayInPlace(array2);
console.log(array2);
