var every = function (array, predicate) {
	for (var i = 0; i < array.length; i++) {
		if (!predicate(array[i])) { return false; }
	}
	return true;
};

var some = function (array, predicate) {
	for (var i = 0; i < array.length; i++) {
		if (predicate(array[i])) { return true; }
	}
	return false;
};

console.log(every([NaN, NaN, NaN], isNaN));
console.log(every([NaN, NaN, 4], isNaN));
console.log(some([NaN, 2, 3], isNaN));
console.log(some([1, 2, 3], isNaN));
