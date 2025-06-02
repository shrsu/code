tokens = input().split(" ")
operators = "+-*/"
stack = []

for token in tokens:
    if token in operators:
        op2 = stack.pop()
        op1 = stack.pop()
        expr = token + " " + op1 + " " + op2
        stack.append(expr)
    else:
        stack.append(token)

print(stack[0])
