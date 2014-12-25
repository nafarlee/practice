var isEven = function (val) {
	val = (val < 0) ? -val : val;

	if (val === 1) {
		return false;
	}
	else if (val === 0) {
		return true;
	}
	else {
		return isEven(val-2);
	}
};

console.log(isEven(50));
console.log(isEven(75));
console.log(isEven(-1));
console.log(isEven(-2));
