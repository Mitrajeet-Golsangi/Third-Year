/**
 * Validate the json object against the given schema
 *
 * @param {JSON} json The JSON Object to create
 * @param {JSON} schema The JSON Schema against to which validating the JSON object
 */
const validate = (json, schema) => {
	const props = schema.properties;
	for (key in props) {
		if (typeof json[key] === props[key].type) {
			if (props[key].pattern) {
				props[key].pattern.test(json[key])
					? console.log(`VALID ${key}`)
					: window.alert(`INVALID ${key}`);
			}

			if (props[key].maxLength) {
				json[key].toString().length <= props[key].maxLength
					? console.log("VALID LENGTH : ", key)
					: window.alert("INVALID Length : ", key);
			}
		}

		else window.alert(`${json[key]} is not of type ${props[key].type}`)
		// else console.log(`${json[key]} is not of type ${props[key].type}`);
	}
};

const schema = {
	$schema: "https://json-schema.org/draft/2020-12/schema",
	$id: "https://example.com/product.schema.json",
	title: "Student Data",
	description: "A Student information schema",
	type: "object",
	properties: {
		name: { type: "string" },
		email: {
			type: "string",
			pattern:
				/^\s*[\w\-\+_]+(\.[\w\-\+_]+)*\@[\w\-\+_]+\.[\w\-\+_]+(\.[\w\-\+_]+)*\s*$/,
		},
		phone: { type: "number", maxLength: 10 },
		division: { type: "string" },
		rollNumber: { type: "number" },
		prnNumber: { type: "number", maxLength: 8 },
	},
};

let data = {
	name: "Mitrajeet Golsangi",
	email: "mitrajeet.golsangi20@vit.edu",
	phone: 9922689422,
	division: "B",
	rollNumber: 01,
	prnNumber: 12010484,
};

validate(data, schema);
