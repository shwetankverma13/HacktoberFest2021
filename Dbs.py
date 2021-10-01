from sys import stdin, stdout 
from collections import defaultdict as D
from collections import deque
def II():
	return map(int,input().split())
def ii():
	return int(input())
def infi():
    return float("Inf")
def mino():
    return -1
class Graph: 
    def __init__(self):
        self.graph = D(list)
        self.Time=0
    
    def addEdge(self, v, w):
        self.graph[v].append(w)
    def BFS(self,u):
        qu=deque()
        qu.append(u)
        self.visited[u]=True
        x=[]
        while qu:
            s=qu.popleft()
            x.append(s)
            for i in self.graph[s]:
                if self.visited[i]==0:
                    qu.append(i)
                    self.visited[i]=True
    def Bfs(self,n):
        self.c=0
        self.visited=D(int)
        for i in range(1,n+1):
            if not self.visited[i]:
                self.BFS(i)
                self.c+=1
    def DFSt(self, s):
        stack=[s]
        self.dpt[s]=1
        self.prev[s]=-1
        while len(stack)!=0:
            s=stack.pop()
            if not self.visited[s]:
                
                for i in self.graph[s]:
                    if not self.visited[i]:
                        stack.append(i)
                        self.prev[i]=s
                        self.dpt[i]=self.dpt[s]+1
            self.visited[s]=1
    def DFS(self):
        self.visited=D(int)
        self.dpt=D(int)
        self.prev=D(bool)
        for i in self.graph:
            if not self.visited[i]:
                self.DFSt(i)
