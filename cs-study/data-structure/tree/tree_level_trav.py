'''
레벨 순회 알고리즘
1. 큐 생성 및 초기화
2. 큐에 루트 노드 삽입
3. 큐가 empty될때까지 반복
    4. n = dequeue front
    5. visit n
    6. if n.left: enqueue(n.left)
    7. if n.right: enqueue(n.right)
'''

from collections import deque

class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
    
    def insert(self, data):
        if not self.data: # if new is root
            self.data = data
            return
        if data < self.data:
            if self.left is None:
                self.left = Node(data)
            else:
                self.left.insert(data)
        else:
            if self.right is None:
                self.right = Node(data)
            else:
                self.right.insert(data)

    def inorder(self):
        if self.left:
            self.left.inorder()
        print(self.data, end=' ')
        if self.right:
            self.right.inorder()
    

def level_traverse(root: Node):
    queue = deque([])
    queue.append(root)
    while queue:
        front = queue.popleft()
        print(front.data, end=' ')
        if front.left:
            queue.append(front.left)
        if front.right:
            queue.append(front.right)
    print()


tree = Node(5)
tree.insert(10)
tree.insert(-910)
tree.insert(345)
tree.insert(3)
tree.insert(45)
tree.insert(-87)
tree.insert(1001)
tree.insert(234)
tree.insert(-37)

tree.inorder()
print()
level_traverse(tree)
