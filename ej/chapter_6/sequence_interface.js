function ArraySeq (array) {
	this.array = array;
	this.position = -1;
}
ArraySeq.prototype.next = function() {
	if (this.position < this.array.length-1) {
		this.position++;
		return true;
	}
	else {
		return false;
	}
};
ArraySeq.prototype.current = function() {
	return this.array[this.position];
};


function RangeSeq (from, to) {
	this.value = from-1;
	this.end = to;
}
RangeSeq.prototype.next = function () {
	if (this.value < this.end-1) {
		this.value++;
		return true;
	}
	else {
		return false;
	}
};
RangeSeq.prototype.current = function () {
	return this.value;
};


var logNum = function (num) {
	return function (sequence) {
		var count = 0;
		while (count < num && sequence.next()) {
			console.log(sequence.current());
			count++;
		}
	};
};


var logFive = logNum(5);
logFive(new ArraySeq([1, 2, 3, 4, 5, 6, 7]));
logFive(new RangeSeq(100, 200));
