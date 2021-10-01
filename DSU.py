def find_set(parent,v):
    stack=[v,0]
    while stack:
        anymore=False
        x,y=stack[-2],stack[-1]
        if parent[x]!=x and y==0:
            anymore=True
            stack[-1]=1
            stack.append(parent[x])
            stack.append(0)
        elif parent[x]==x:
            dada=parent[x]
            anymore=False
        else:
            anymore=False
        if anymore==False:
            parent[x]=dada
            stack.pop()
            stack.pop()
    return parent[v]
def union_set(a,b,size,parent,brk):
    u,v=a,b
    a = find_set(parent,a)
    b = find_set(parent,b)
    if (a != b) :
        if (size[a] < size[b]):
            a,b=b,a
        parent[b] = a
        size[a] += size[b]
    else:
        brk.append([u,v])
n=int(input())
parent=[i for i in range(n)]
size=[1]*n
print(parent)
print(size)
for i in range(n-1):
    a,b=map(int,input().split())
    union_set(a-1,b-1,size,parent)
print(parent)
print(size)
