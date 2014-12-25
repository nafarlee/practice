var range = function (start, end, step) {
	step = (typeof(step) === 'undefined') ? 1 : step;

	var array = [];
	if (start <= end && step > 0) {
		for (; start <= end; start+=step) {
			console.log(start);
			array.push(start);
		}
	}
	else {
		for(; start >= end; start+=step) {
			array.push(start);
		}
	}

	return array;
};

var sum = function(array) {
	var sum = 0;

	for (var i = 0; i < array.length; i++) {
		sum += array[i];
	}
};

console.log(range(1, 10));
console.log(range(5, 2, -1));
