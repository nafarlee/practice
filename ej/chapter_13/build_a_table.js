var buildTable = function(data) {
	"use strict";
	var table = document.createElement("table");
	for (var rows = 0; rows < data.length+1; rows++) {
		table.appendChild(document.createElement("tr"));
	}

	var headings = Object.keys(data[0]);
	headings.forEach(function (heading) {
		var table_heading = document.createElement("th");
		table_heading.textContent = heading;
		table.firstChild.appendChild(table_heading);
	});

	var appendValuesToTable = function(value) {
		var td = document.createElement("td");
		td.textContent = value;
		if (typeof value === "number") {
			td.style.textAlign = "right";
		}
		table.childNodes[entries].appendChild(td);
	};

	var getObjectValues = function (object) {
		var values = [];
		Object.keys(object).forEach(function(key){
			values.push(object[key]);
		});
		return values;
	};

	for (var entries = 1; entries < table.childNodes.length; entries++) {
		getObjectValues(data[entries-1]).forEach(appendValuesToTable);
	}
	return table;
};
