class HeightAndStartingIndexPair:
    def __init__(self, height, start):
        self.height = height
        self.start = start

n = int(input("Enter number of bars: "))
heights = list(map(int, input("Enter heights: ").split()))

stack = []
max_area = 0

for index, height in enumerate(heights):
    start = index

    while stack and stack[-1].height >= height:
        top = stack.pop()
        area = (index - top.start) * top.height
        max_area = max(max_area, area)
        start = top.start 

    stack.append(HeightAndStartingIndexPair(height, start))

while stack:
    bar = stack.pop()
    area = (n - bar.start) * bar.height
    max_area = max(max_area, area)

print("Maximum Area:", max_area)
