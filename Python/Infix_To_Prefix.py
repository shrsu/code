def is_operator(c):
    return c in ['+', '-', '*', '/', '^']

def precedence(c):
    if c == '^':
        return 3
    elif c == '*' or c == '/':
        return 2
    elif c == '+' or c == '-':
        return 1
    else:
        return -1

def infix_to_prefix(infix):
    infix = infix[::-1]
    
    infix = ''.join(['(' if c == ')' else ')' if c == '(' else c for c in infix])

    stack = []
    result = []

    for c in infix:
        if c.isalnum():  
            result.append(c)
        elif c == '(':
            stack.append(c)
        elif c == ')':
            while stack and stack[-1] != '(':
                result.append(stack.pop())
            stack.pop()  
        elif is_operator(c):
            while (stack and precedence(c) < precedence(stack[-1])):
                result.append(stack.pop())
            while (stack and precedence(c) == precedence(stack[-1]) and c != '^'):
                result.append(stack.pop())
            stack.append(c)

    while stack:
        result.append(stack.pop())

    return ''.join(result[::-1])

infix_expr = "(A-B/C)*(A/K-L)"
prefix_expr = infix_to_prefix(infix_expr)
print("Prefix expression:", prefix_expr)
