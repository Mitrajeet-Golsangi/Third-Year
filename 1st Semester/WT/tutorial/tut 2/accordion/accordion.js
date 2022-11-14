const items = Array.from(document.querySelectorAll(".body"));
const headings = Array.from(document.querySelectorAll(".heading"));

headings.forEach((heading, idx) => {
	heading.addEventListener("click", () =>
		items.map(
			(i, innerIdx) =>
				(i.style.display =
					innerIdx !== idx
						? "none"
						: i.style.display === "block"
						? "none"
						: "block")
		)
	);
});
