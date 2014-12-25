var white_row = function (length) {
	var row = "";

	for (var i = 1; i <= length; i++) {
		row += (i % 2 === 0) ? "#" : " ";
	}

	return row;
};

var black_row = function (length) {
	var row = "";

	for (var i = 1; i <= length; i++) {
		row += (i % 2 === 0) ? " " : "#";
	}

	return row;
};

{
	var size = 30;
	var chess_board = "";
	for (var i = 1; i <= size; i++) {
		chess_board += (i % 2 === 0) ? black_row(size) : white_row(size);
		chess_board += '\n';
	}
	console.log(chess_board);
}
