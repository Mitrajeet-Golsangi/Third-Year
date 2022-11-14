document.getElementById("admission-form").addEventListener("submit", (e) => {
	e.preventDefault();

	Array.from(document.forms[0].elements).forEach((i) => {
		switch (i.id) {
			case "email":
				let filter =
					/^\s*[\w\-\+_]+(\.[\w\-\+_]+)*\@[\w\-\+_]+\.[\w\-\+_]+(\.[\w\-\+_]+)*\s*$/;

				if (!filter.test(i.value)) {
					document.getElementById("basic-information").classList.add("show");
					document
						.getElementById("basic-information-header")
						.classList.add("text-danger");
					document
						.getElementById("basic-information-header")
						.classList.remove("text-primary");
					document.getElementById("email").classList.add("border-danger");
					i.setCustomValidity("Enter a Valid Email !");
				} else {
					document
						.getElementById("basic-information-header")
						.classList.add("text-primary");
					document
						.getElementById("basic-information-header")
						.classList.remove("text-danger");
					document.getElementById("email").classList.remove("border-danger");

					i.setCustomValidity("");
				}

				i.addEventListener("input", (e) => e.target.setCustomValidity(""));
				break;
			case "telephone-number":
				let telephoneFilter = /^(\+0?1\s)?\(?\d{3}\)?[\s.-]\d{3}[\s.-]\d{4}$/;

				if (!telephoneFilter.test(i.value)) {
					document.getElementById("basic-information").classList.add("show");
					document
						.getElementById("basic-information-header")
						.classList.add("text-danger");
					document
						.getElementById("basic-information-header")
						.classList.remove("text-primary");
					document
						.getElementById("telephone-number")
						.classList.add("border-danger");
					i.setCustomValidity("Enter a Valid Telephone Number !");
				} else {
					document
						.getElementById("basic-information-header")
						.classList.add("text-primary");
					document
						.getElementById("basic-information-header")
						.classList.remove("text-danger");
					document
						.getElementById("telephone-number")
						.classList.remove("border-danger");

					i.setCustomValidity("");
				}

				i.addEventListener("input", (e) => e.target.setCustomValidity(""));
				break;

			default:
				try {
					if (i.value === null || i.value === "" || i.value === undefined) {
						document.getElementById(i.id).classList.add("border-danger");
						try {
							i.setCustomValidity(i.getAttribute("data-invalid-feedback"));
						} catch (_) {
							document
								.getElementsByClassName("accordion-collapse")
								.forEach((i) => i.classList.add("show"));
						}
					} else {
						document.getElementById(i.id).classList.remove("border-danger");
						i.setCustomValidity("");
					}
					i.addEventListener("input", (e) => e.target.setCustomValidity(""));
				} catch (_) {}
		}
	});

	// e.target.submit();
});
