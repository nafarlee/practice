<img src="img/cat.png" id="cat" style="position: absolute">
<img src="img/hat.png" id="hat" style="position: absolute">

<script>
var hat = document.querySelector("#hat");
var cat = document.querySelector("#cat");
document.body.style.height =  "600px";

var animate = function (time) {
	var centerX = document.body.clientWidth / 2;
	var centerY = document.body.clientHeight / 2;
	var angleModifier = .001;
	var angle = time * angleModifier;

	var catArcWidth = 300;
	var catArcHeight = 70;
	var catX = Math.cos(angle) * catArcWidth + centerX - 30;
	var catY = Math.sin(angle) * catArcHeight + centerY;

	var hatSpeed = 5;
	var hatArcWidth = 80;
	var hatArcHeight = 120;
	var hatX = catX + Math.cos(angle * 5) * hatArcWidth;
	var hatY = catY + Math.sin(angle * 5) * hatArcHeight;

	cat.style.top = catY + "px";
	cat.style.left = catX + "px";
	hat.style.top = hatY + "px";
	hat.style.left = hatX + "px";
	requestAnimationFrame(animate);
};

requestAnimationFrame(animate);
</script>
