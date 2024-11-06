// evaluate the following postfix expression using stack (show all the steps) 4,3,-,6,2,+,,8,2,/,6,,-
/*
Step-by-Step Evaluation:
Initial Stack: Empty stack

Read the first operand: 4

Push 4 onto the stack: [4]
Read the second operand: 3

Push 3 onto the stack: [4, 3]
Read the operator: -

Pop two operands from the stack: 3 and 4
Perform the operation: 4 - 3 = 1
Push the result onto the stack: [1]
Read the next operand: 6

Push 6 onto the stack: [1, 6]
Read the next operand: 2

Push 2 onto the stack: [1, 6, 2]
Read the operator: +

Pop two operands from the stack: 2 and 6
Perform the operation: 6 + 2 = 8
Push the result onto the stack: [1, 8]
Read the operator: *

Pop two operands from the stack: 8 and 1
Perform the operation: 1 * 8 = 8
Push the result onto the stack: [8]
Read the next operand: 8

Push 8 onto the stack: [8, 8]
Read the next operand: 2

Push 2 onto the stack: [8, 8, 2]
Read the operator: /

Pop two operands from the stack: 2 and 8
Perform the operation: 8 / 2 = 4
Push the result onto the stack: [8, 4]
Read the next operand: 6

Push 6 onto the stack: [8, 4, 6]
Read the operator: *

Pop two operands from the stack: 6 and 4
Perform the operation: 4 * 6 = 24
Push the result onto the stack: [8, 24]
Read the operator: -

Pop two operands from the stack: 24 and 8
Perform the operation: 8 - 24 = -16
Push the result onto the stack: [-16]
*/