

class Heap:
    def __init__(self):
        self.array = []
        self.size = 0

    def __getParentIndex(self, index):
        return (index - 1)//2

    def __bubbleUpMax(self):
        index = self.size - 1
        while index > 0 and self.array[index] > self.array[self.__getParentIndex(index)]:
            self.array[index], self.array[self.__getParentIndex(
                index)] = self.array[self.__getParentIndex(index)], self.array[index]
            index = self.__getParentIndex(index)

    def __bubbleUpMin(self):
        index = self.size - 1
        while index > 0 and self.array[index] < self.array[self.__getParentIndex(index)]:
            self.array[index], self.array[self.__getParentIndex(
                index)] = self.array[self.__getParentIndex(index)], self.array[index]
            index = self.__getParentIndex(index)

    def __checkPositionMin(self, i):
        smallerIndex = i

        leftIndex = i * 2 + 1
        if leftIndex < self.size and self.array[leftIndex] < self.array[smallerIndex]:
            smallerIndex = leftIndex

        rightIndex = i * 2 + 2
        if rightIndex < self.size and self.array[rightIndex] < self.array[smallerIndex]:
            smallerIndex = rightIndex

        if smallerIndex == i:
            return

        self.array[i], self.array[smallerIndex] = self.array[smallerIndex], self.array[i]
        self.__checkPositionMin(smallerIndex)

    def __checkPositionMax(self, index):
        largerIndex = index

        leftChildIndex = index * 2 + 1
        if leftChildIndex < self.size and self.array[leftChildIndex] > self.array[largerIndex]:
            largerIndex = leftChildIndex

        rightChildIndex = index * 2 + 2
        if rightChildIndex < self.size and self.array[rightChildIndex] > self.array[largerIndex]:
            largerIndex = rightChildIndex

        if index == largerIndex:
            return

        self.array[index], self.array[largerIndex] = self.array[largerIndex], self.array[index]
        self.__checkPositionMax(largerIndex)

    def __resetRoot(self):
        root = self.array[0]
        self.array[0] = self.array[self.size-1]
        self.size -= 1
        return root

    def __removeReturn(self, root):
        self.array[self.size] = root
        return root

    def insertInMaxHeap(self, data):
        self.array.append(data)
        self.size += 1
        self.__bubbleUpMax()

    def insertInMinHeap(self, data):
        self.array.append(data)
        self.size += 1
        self.__bubbleUpMin()

    def removeMax(self):
        if self.isEmpty():
            return "Empty"

        root = self.__resetRoot()

        for i in range(self.size):
            self.__checkPositionMax(i)

        return self.__removeReturn(root)

    def removeMin(self):
        if self.isEmpty():
            return "Empty"

        root = self.__resetRoot()

        for i in range(self.size):
            self.__checkPositionMin(i)

        return self.__removeReturn(root)

    def getRoot(self):
        return self.array[0]

    def getList(self):
        return self.array

    def isEmpty(self):
        return self.size == 0

    def __heapify(self, arr, index):
        largerIndex = index

        leftChild = index * 2 + 1
        if leftChild < len(arr) and arr[leftChild] > arr[largerIndex]:
            largerIndex = leftChild

        rightChild = index * 2 + 2
        if rightChild < len(arr) and arr[rightChild] > arr[largerIndex]:
            largerIndex = rightChild

        if index == largerIndex:
            return

        arr[index], arr[largerIndex] = arr[largerIndex], arr[index]
        self.__heapify(arr, largerIndex)

    def heapify(self, arr):

        lastParentIndex = len(arr) // 2 - 1
        for i in range(lastParentIndex, -1, -1):
            self.__heapify(arr, i)

        return arr

    def heapSort(self, array):

        for i in range(len(array)):
            self.insertInMaxHeap(array[i])

        for i in range(len(self.array)):
            array[self.size] = self.removeMax()

        return array


maxheap = Heap()

numbers = [15, 5, 78, 1, 422, 2]

print(maxheap.heapify([7, 3, 9, 1, 32, 879, 133]))
print(maxheap.heapSort([7, 3, 9, 1, 32, 879, 133]))

# print(maxheap.heapSort([5, 10, 4, 1, 3, 2]))

# print(maxheap.removeMax())

# maxheap.insertInMaxHeap(15)
# maxheap.insertInMaxHeap(3)
# maxheap.insertInMaxHeap(78)
# maxheap.insertInMaxHeap(1)
# maxheap.insertInMaxHeap(422)
# maxheap.insertInMaxHeap(2)

# print("Max: ", maxheap.getRoot())

# print(maxheap.removeMax())
# print(maxheap.removeMax())
# print(maxheap.removeMax())
# print(maxheap.removeMax())
# print(maxheap.removeMax())

# print(maxheap.getList())

# print("----------------------------------")
# print("----------------------------------")


# minheap = Heap()

# print(minheap.removeMin())

# minheap.insertInMinHeap(15)
# minheap.insertInMinHeap(3)
# minheap.insertInMinHeap(78)
# minheap.insertInMinHeap(1)
# minheap.insertInMinHeap(422)
# minheap.insertInMinHeap(2)

# print("Min: ", minheap.getRoot())

# print(minheap.removeMin())
# print(minheap.removeMin())
# print(minheap.removeMin())
# print(minheap.removeMin())
# print(minheap.removeMin())

# print(minheap.getList())
# 15,3,78,1,422,2
