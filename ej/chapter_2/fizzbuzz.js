var fizzbuzz = function (num) {
	if (num < 3) {
		return num;
	}
	else if (divisible_by(num, 3)) {
		if (divisible_by(num, 15)) {
			return "FizzBuzz";
		}
		return "Fizz";
	}
	else if (divisible_by(num, 5)) {
		return "Buzz";
	}
};

var divisible_by = function(numerator, denominator) {
	return (numerator % denominator === 0);
};

(function () {
	for (var index = 1; index <= 100; index ++) {
		console.log(fizzbuzz(index));
	}
}());
