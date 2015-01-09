var ancestors = JSON.parse(require('./ancestry'));

var groupBy = function (array, func) {
	var group = {};
	array.forEach(function(element) {
		var groupKey = func(element);
		if (groupKey in group) {
			group[groupKey].push(element);
		}
		else {
			group[groupKey] = [element];
		}
	});

	return group;
};

var isEven = function (num) {
	if (num % 2 === 0) return "even";
	else return "odd";
};

var nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

console.log(groupBy(nums, isEven));
