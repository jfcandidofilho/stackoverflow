table_ID = "tableOfInterest";

table_lines = document.getElementById(table_ID);

alert(document.getElementById(table_ID).childrenElementCount);

if(table_lines != null)
	console.log("LOG: " + table_lines);// + number_of_lines);
else
	console.log("LOG: nulo!");
