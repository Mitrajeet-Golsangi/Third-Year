const main = () => {
	// --------------------------- String Functions --------------------------- //
	const strDomElem = document.getElementById("string-functions");

	let a = "Hello World";
	let str = `<li>${a.replace("Hello", "Yello")}</li>
	<li>${a.indexOf("W")}</li>
	<li>${a.substring(3)}</li>
	<li>${a.lastIndexOf("o")}</li>
	<li>${a.charAt(2)}</li>
	<li>${a.includes("Hello")}</li>`;

	strDomElem.innerHTML = str;
	// ---------------------------- Array Functions --------------------------- //

	let arr = [];

	for (let i = 0; i < 10; i++) {
		arr.push(i);
	}
	console.log(arr);
	arr.forEach((i) => console.log(i));
	arr.filter((i) => (i <= 5 ? console.log(`Filter for : ${i}`) : null));
	console.log(arr.length);

	// -------------------------- Navigator Functions ------------------------- //
};

const openWindows = () => {
	// window.open("https://www.google.com");
	// window.replace("https://www.google.com");
	console.log(window.navigator);
	console.log(window.navigator.cookieEnabled);
};
