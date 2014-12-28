var array = [ [1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]];

console.log(array.reduce(function (flattened, arr) {
	return flattened.concat(arr);
}));
