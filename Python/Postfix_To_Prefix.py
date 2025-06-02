tokens = input().split(" ")
operators = "+-*/"
stack = []

for token in tokens[::-1]:
    if token in operators:
        op1 = stack.pop()
        op2 = stack.pop()
        expr = token + " " + op1 + " " + op2
        stack.append(expr)
    else:
        stack.append(token)

print(stack[0])
