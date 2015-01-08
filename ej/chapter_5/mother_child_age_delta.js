var ancestors = JSON.parse(require('./ancestry'));

var byName = {};
ancestors.forEach(function(person) {
	byName[person.name] = person;
});

var hasMother = function (person) { return person.mother !== null; };
var motherInData = function (person) {return byName[person.mother] !== undefined; };
var average = function (array) { function plus(a, b) {return a + b;} return array.reduce(plus) / array.length; };
var maternityAge = function (person) {return person.born - byName[person.mother].born; };

var momAgesAtBirth = ancestors.filter(hasMother).filter(motherInData).map(maternityAge);
console.log(average(momAgesAtBirth));
