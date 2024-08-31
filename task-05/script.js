let products = [];
let cart = [];
let cartTotal = 0;

function terminaloutput(output) {
    const terminaloutput = document.querySelector('.terminal-output');
    terminaloutput.innerHTML += `<div>${output}</div>`;
    terminaloutput.scrollTop = terminaloutput.scrollHeight;
}

async function fetchproducts() {
    try {
        const response = await fetch('https://fakestoreapi.com/products?limit=20');
        products = await response.json();
        displayProducts(products);
    } catch (error) {
        terminaloutput(`Failed to fetch products: ${error}`);
    }
}

function listproducts() {
    products.forEach(product => {
        terminaloutput(`${product.id}: ${product.title} - $${product.price}`);
    });
}

function viewProductDetails(id) {
    const product = products.find(p => p.id === parseInt(id));
    if (product) {
        terminaloutput(`ID: ${product.id}\nName: ${product.title}\nPrice: $${product.price}\nDescription: ${product.description}`);
    } else {
        terminaloutput(`Product with ID ${id} not found.`);
    }
}

function updateCartTotal() {
    const cartTotalElement = document.getElementById('carttotal');
    cartTotalElement.innerHTML = `$${cartTotal.toFixed(2)}`;
}

function addproduct(id) {
    const product = products.find(p => p.id == parseInt(id));
    if (product) {
        cart.push(product);
        cartTotal += product.price; 
        terminaloutput(`${product.title} has been added to the cart`);
        updateCartTotal(); 
    } else {
        terminaloutput('Product not found');
    }
}

function removeproduct(id) {
    const index = cart.findIndex(p => p.id === parseInt(id));
    if (index > -1) {
        const removedProduct = cart.splice(index, 1);
        cartTotal -= removedProduct[0].price; 
        terminaloutput(`${removedProduct[0].title} removed`);
        updateCartTotal(); 
    } else {
        terminaloutput('Product not found');
    }
}

function viewcart() {
    if (cart.length === 0) {
        terminaloutput('Cart is empty');
    } else {
        cart.forEach(item => {
            terminaloutput(`${item.id}: ${item.title} - $${item.price}`);
        });
    }
}

function clearterminal() {
    const terminaloutput = document.querySelector('.terminal-output');
    terminaloutput.innerHTML = '';
}

function searchproduct(name) {
    const results = products.filter(product => product.title.toLowerCase().includes(name.toLowerCase()));
    if (results.length > 0) {
        results.forEach(product => {
            terminaloutput(`${product.id}: ${product.title} - $${product.price}`);
        });
    } else {
        terminaloutput('No matches found');
    }
}

function sortproducts(criteria) {
    let sortedproducts;
    if (criteria === 'price') {
        sortedproducts = products.slice().sort((a, b) => a.price - b.price);
    } else if (criteria === 'name') {
        sortedproducts = products.slice().sort((a, b) => a.title.localeCompare(b.title));
    } else {
        terminaloutput('Invalid sorting criteria');
        return;
    }

    sortedproducts.forEach(product => {
        terminaloutput(`${product.id}: ${product.title} - $${product.price}`);
    });
}

function checkout() {
    window.location.href = 'checkout.html';
}

function helpcommand() {
    terminaloutput("list: Display all available products.\n details 'product_id': View details of a specific product identified by its ID.\n add 'product_id': Add a specific product to your cart using its ID.\n remove 'product_id': Remove a specific product from your cart using its ID.\n cart: View the current items in your cart.\n buy: Proceed to a new webpage where you can review items in your cart along with the total price, enabling you to finalize your purchase.\n clear: Clear the terminal screen.\n search 'product_name': Search for a product by name.\n sort 'price/name': Sort the products based on price or name.");
}

function handleCommand(command) {
    const [cmd, ...args] = command.split(' ');
    switch (cmd.toLowerCase()) {
        case 'list':
            listproducts();
            break;
        case 'details':
            viewProductDetails(args[0]);
            break;
        case 'add':
            addproduct(args[0]);
            break;
        case 'remove':
            removeproduct(args[0]);
            break;
        case 'cart':
            viewcart();
            break;
        case 'buy':
            checkout();
            break;
        case 'clear':
            clearterminal();
            break;
        case 'search':
            searchproduct(args.join(' '));
            break;
        case 'sort':
            sortproducts(args[0]);
            break;
        case 'help':
            helpcommand();
            break;
        default:
            terminaloutput(`Command '${cmd}' not recognized`);
    }
}

document.querySelector('input[type="text"]').addEventListener('keypress', function (e) {
    if (e.key === 'Enter') {
        handleCommand(e.target.value);
        e.target.value = '';
    }
});

fetchproducts();

function displayProducts(products) {
    const productGrid = document.getElementById('product-grid');
    const template = document.querySelector('.product-box.template');

    products.forEach(product => {
        const productBox = template.cloneNode(true); 
        productBox.classList.remove('template'); 

        productBox.querySelector('.product-img').src = product.image;
        productBox.querySelector('.product-img').alt = product.title;
        productBox.querySelector('.product-title').textContent = product.title;
        productBox.querySelector('.product-price').textContent = `$${product.price}`;
        productBox.querySelector('.product-hover').textContent = product.title;

        productBox.style.backgroundColor = getRandomColor();

        productGrid.appendChild(productBox); 
    });
}

function getRandomColor() {
    const colors = ['#FFB6C1', '#87CEFA', '#FFD700', '#98FB98', '#FFA07A', '#AFEEEE', '#E6E6FA', '#FF6347', '#7FFFD4', '#FFFACD'];
    return colors[Math.floor(Math.random() * colors.length)];
}

document.addEventListener('DOMContentLoaded', fetchproducts);
