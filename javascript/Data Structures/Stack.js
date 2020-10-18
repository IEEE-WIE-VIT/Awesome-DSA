//adding and removing elements from stack
let Stack = []; 

//adding elements to stack, push

stack.push(6);
console.log(stack); 
//Stack: [6]

stack.push(9);
console.log(stack);
//Stack: [6,9]

stack.push(1);
console.log(stack);
//Stack: [6,9,1]


//removing and returning top elements, pop

console.log(stack.pop()); 
//1
console.log(stack); 
//Stack: [6,9];

console.log(stack.pop());
//9
console.log(stack); 
//Stack: [6]

console.log(stack.pop());
//6
console.log(stack); 
//Stack: []

console.log(stack.pop());
//undefined
console.log(stack); 
