<h1>Heading with a <span>span</span> element.</h1>
<p>A paragraph with <span>one</span>, <span>two</span>
  spans.</p>

<script>
  function byTagName(node, tagName) {
	  var upperName = tagName.toUpperCase();
	  var tags = [];

	  if (node.tagName === upperName) {
		  tags.push(node);
	  }
	  if (node.hasChildNodes()) {
		  var childrenArray = Array.prototype.slice.call(node.childNodes, 0);
		  childrenArray.forEach(function (child) {
			  tags = tags.concat(byTagName(child, tagName));
		  });
	  }

	  return tags;
  }

  console.log(byTagName(document.body, "h1").length);
  // → 1
  console.log(byTagName(document.body, "span").length);
  // → 3
  var para = document.querySelector("p");
  console.log(byTagName(para, "span").length);
  // → 2
</script>
