var arrayToList = function (array) {
	var root = {};
	var node = root;
	for (var i = 0; i < array.length; i++) {
		node.value = array[i];
		node.rest = {};
		node = node.rest;
	}
	return root;
};

var listToArray = function (list) {
	var array = [];
	var index = 0;
	var node = list;
	while (typeof(node.rest) !== "undefined") {
		array[index] = node.value;
		index++;
		node = node.rest;
	}

	return array;
};

var prepend = function (list, element) {
	element.rest = list;
};

// 2 4 6 8
// 1 2 3 4
var nth = function (list, position) {
	var node = list;
	for (var i = 0; i < position; i++) {
		node = node.rest;
	}
	
	return node;
};

var nth_recursive = function (list, position) {
	var node = list;
	if (position === 0) {
		return node;
	}
	else {
		return nth_recursive(list.rest, position-1);
	}
};

var array = [1, 4, 9, 16, 25];
var list = arrayToList(array);
console.log(listToArray(list));
console.log(nth(list,2).value);
console.log(nth_recursive(list,2).value);
