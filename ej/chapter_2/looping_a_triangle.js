var loop_triangle = function (func, reps) {
	var message;
	for (var index = 1; index < reps; index++) {
		message += func('#', index);
		message += '\n';
	}
	return message;
};

var character_repeat = function (character, reps) {
	var message;
	for (var index = 0; index < reps; index++) {
		message += character;
	}
	return message;
};

(function () {
	console.log(loop_triangle(character_repeat, 8));
})();
