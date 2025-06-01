digits = list(input())
k = int(input())

stack = []

for digit in digits:
    digit = int(digit)
    while stack and k > 0 and digit < stack[-1]:
        stack.pop()
        k -= 1
    stack.append(digit)

while k > 0 and stack:
    stack.pop()
    k -= 1

result = "".join(str(d) for d in stack).lstrip("0")
print(result if result else "0")
