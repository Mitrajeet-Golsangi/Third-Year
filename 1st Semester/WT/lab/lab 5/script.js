const input = document.getElementById('input');
const form = document.getElementsByTagName('form')[0]
let i = 1;

function createElementInput(i) {
    let div = document.createElement('div');
    let label = document.createElement('label');
    let input = document.createElement('input');

    div.className = "form-group";

    label.className = "form-label";
    label.id = `label-${i}`;
    label.innerHTML = `Array Element ${i}`;

    input.className = "form-control";
    input.id = `input-${i}`;

    div.appendChild(label);
    div.appendChild(input);

    return div;
}

function reverse(arr) {
    let op = [];
    for (let i = arr.length - 1; i >= 0; i--) {
        op.push(arr[i]);
    }
    return op;
}

document.getElementById('add-btn').addEventListener('click', () => {

    form.appendChild(createElementInput(i));
    i++;

})

document.getElementById('reverse-btn').addEventListener('click', () => {
    let arr = [];

    for (let index = 0; index < i; index++) {
        arr.push(parseInt(document.getElementById(`input-${index}`).value))
    }
    
    arr = reverse(arr);

    document.getElementById('output').innerHTML = arr;
})
