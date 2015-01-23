var StretchCell = function (inner, width, height) {
	this.inner = inner;
	this.height = height;
	this.width = width;
};

StretchCell.prototype.minWidth = function() {
	return Math.max(this.inner.minWidth(), this.width);
};

StretchCell.prototype.minHeight = function() {
	return Math.max(this.inner.minHeight(), this.height);
};

StretchCell.prototype.draw = function(width, height) {
	this.inner.draw(width, height);
};

var sc = new StretchCell(new TextCell("abc"), 1, 2);
