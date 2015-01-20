var ancestors = JSON.parse(require('./ancestry'));

var average = function(array) {
	var plus = function (a, b) {return a + b; };
	return array.reduce(plus) / array.length;
};

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

var assignCentury = function (person) {
	return Math.ceil(person.died / 100);
};

var getAge = function (person) {
	return person.died - person.born;
};

var centuries = groupBy(ancestors, assignCentury);
for (var key in centuries) {
	var ages = centuries[key].map(getAge);
	console.log(key + ": " + average(ages));
}
