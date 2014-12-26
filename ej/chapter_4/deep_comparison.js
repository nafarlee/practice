/*
{
	value: 1,
	obj: {
		shit: 1
	}
}
*/

var deepEqual = function(a, b) {
	if (typeof(a) !== typeof(b)) {
		console.log("They are not the same type");
		return false;
	}
	else {
		var equal = true;
		for (var keys in a) {
			if (typeof(a[keys]) == "object") {
				console.log(keys + " is of type of object");
				equal = equal && deepEqual(a[keys], b[keys]);
			}
			else {
				console.log(keys + " is not an object");
				equal = equal && (a[keys] === b[keys]);
			}
		}

		return equal;
	}
};

var obj1 = {
	value: 12,
	string: "banana",
	more: {
		value: "apples"
	}
};

var obj2 = {
	value: 12,
	string: "banana",
	more: {
		value: "apples"
	}
};

var obj3 = 8;

var obj4 = obj2;

var obj5 = {
	zalue: 12,
	ztring: "banana",
	zore: {
		value: "apples"
	}
};

console.log("\n" + deepEqual(obj1, obj3));
console.log("\n" + deepEqual(obj1, obj2));
console.log("\n" + deepEqual(obj4, obj2));
console.log("\n" + deepEqual(obj4, obj5));
