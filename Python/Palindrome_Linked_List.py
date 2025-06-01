class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        current = self.head
        while current.next is not None:
            current = current.next

        current.next = new_node

    def is_palindrome_reversing_half(self):
        # Not a good approach because it modifies the original list
        slow = self.head
        fast = self.head

        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        node = None
        while slow:
            temp = slow.next
            slow.next = node
            node = slow
            slow = temp

        first, second = self.head, node

        while second:
            if first.data != second.data:
                return False
            first = first.next
            second = second.next

        return True

    def is_palindrome_stack(self):
        stack = []
        slow = fast = self.head

        while fast and fast.next:
            stack.append(slow.val)
            slow = slow.next
            fast = fast.next.next

        if fast:
            slow = slow.next

        while slow:
            if stack.pop() != slow.val:
                return False
            slow = slow.next

        return True
    
n = int(input())
elements = map(int, input().split())

ll = LinkedList()
for ele in elements:
    ll.insert(ele)

print(ll.is_palindrome_reversing_half())
print(ll.is_palindrome_stack())
