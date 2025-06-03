def precedence(op):
    if op in ('+', '-'):
        return 1
    elif op in ('*', '/'):
        return 2
    return 0

def infix_to_prefix(infix_expr):
    def is_operator(c):
        return c in "+-*/"

    def not_greater(op, top_op):
        return precedence(op) <= precedence(top_op)

    infix_expr = infix_expr[::-1]
    infix_expr = ''.join(['(' if c == ')' else ')' if c == '(' else c for c in infix_expr])

    stack = []
    output = []

    for char in infix_expr:
        if char.isalnum():
            output.append(char)
        elif char == '(':
            stack.append(char)
        elif char == ')':
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop() 
        elif is_operator(char):
            while stack and is_operator(stack[-1]) and not_greater(char, stack[-1]):
                output.append(stack.pop())
            stack.append(char)

    while stack:
        output.append(stack.pop())

    return ''.join(output[::-1])

infix = input("Enter infix expression: ")
prefix = infix_to_prefix(infix)
print("Prefix expression:", prefix)
