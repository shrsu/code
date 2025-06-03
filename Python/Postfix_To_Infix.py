def is_operator(token):
    return token in "+-*/"

def postfix_to_infix(postfix_expr):
    stack = []
    tokens = postfix_expr.split()

    for token in tokens:
        if is_operator(token):
            op2 = stack.pop()
            op1 = stack.pop()
            new_expr = f"( {op1} {token} {op2} )"
            stack.append(new_expr)
        else:
            stack.append(token)
    
    return stack[0]

postfix = input("Enter postfix expression: ")
infix = postfix_to_infix(postfix)
print("Infix expression:", infix)
