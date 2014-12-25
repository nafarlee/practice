var countChar = function (s, c) {
	var count = 0;
	for (var i = 0; i < s.length; i++) {
		if (s.charAt(i) === c) {
			count++;
		}
	}

	return count;
};

var countBs = function (s) {
	return countChar(s, 'B');
};

console.log(countChar("Dirty Deeds Done Dirt Cheap", 'D'));
console.log(countBs("BaseBall"));
