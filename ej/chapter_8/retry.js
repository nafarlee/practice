function MultiplicationUnitFailure() {}

function primitiveMultiply(a, b) {
	if (Math.random() < 0.5) return a * b;
	else throw new MultiplicationUnitFailure();
}

function reliableMultiply(a, b) {
	while (true) {
		try {
			return primitiveMultiply(a, b);
		} catch (e) {
			if (e instanceof MultiplicationUnitFailure) continue;
			else throw e;
		}
	}
}

console.log(reliableMultiply(8, 8));
