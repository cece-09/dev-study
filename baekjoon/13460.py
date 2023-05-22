from collections import deque
from dataclasses import dataclass


@dataclass
class Pos:
    row: int = None  # row
    col: int = None  # col
    cnt: int = None  # number of move


@dataclass
class Node:
    R: Pos = None
    B: Pos = None
    cnt: int = None

    def name(self):
        return (self.R.row, self.R.col, self.B.row, self.B.col)


# input
N, M = map(int, input().split())
board = [[0] * M] * N

for i in range(N):
    board[i] = list(input())
    for j in range(M):
        if (board[i][j] == 'R'):
            R = Pos(i, j, 0)
        if (board[i][j] == 'B'):
            B = Pos(i, j, 0)


def move(p: Pos, dir):
    cnt = 0
    r, c = p.row, p.col
    while board[r + dir[0]][c + dir[1]] != '#' and board[r][c] != 'O':
        r += dir[0]
        c += dir[1]
        cnt += 1
    return Pos(r, c, cnt)


def bfs():
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    visited = {}

    q = deque()
    q.append(Node(R, B, 0))

    while q:
        curr: Node = q.popleft()
        visited[curr.name()] = True

        if curr.cnt > 10:
            return -1

        for dir in directions:
            nR: Pos = move(curr.R, dir)
            nB: Pos = move(curr.B, dir)

            if (board[nB.row][nB.col] != 'O'):
                if (board[nR.row][nR.col] == 'O'):
                    return curr.cnt + 1

                # if pos is the same
                if (nR.row == nB.row and nR.col == nB.col):
                    if (nR.cnt > nB.cnt):
                        nR.row -= dir[0]
                        nR.col -= dir[1]
                    else:
                        nB.row -= dir[0]
                        nB.col -= dir[1]

                # insert adjacent to queue
                new = Node(nR, nB, curr.cnt + 1)
                newName = new.name()
                if not (new.name() in visited):
                    visited[new.name()] = True
                    q.append(new)
    return -1


print(bfs())
