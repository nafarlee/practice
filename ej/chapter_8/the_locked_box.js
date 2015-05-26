"use strict";
var box = {
	locked: true,
	unlock: function() {this.locked = false;},
	lock: function() {this.locked = true;},
	_content: [],
	get content() {
		if (this.locked) throw new Error("Locked!");
		return this._content;
	}
};

var withBoxUnlocked = function (func) {
	if (box.locked) box.unlock();
	try {
		return func();
	} finally {
		box.lock();
	}
};

withBoxUnlocked(function() {
	box.content.push("gold piece");
});

try {
	withBoxUnlocked(function() {
	throw new Error("Pirates on the horizon! Abort!");
	});
} catch (e) {
	console.log("Error rasied:", e);


console.log(box.locked);
