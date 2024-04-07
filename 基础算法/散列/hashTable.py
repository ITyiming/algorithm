class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class ChainingHashTable:
    def __init__(self, size):
        """
        初始化散列表的大小和数组
        """
        self.size = size
        self.hash_table = [None] * size

    def _hash(self, key):
        """
        散列函数，将键转换为散列索引
        """
        return key % self.size
    def insert(self, key, value):
        """
        向散列表中插入键值对
        """
        index = self._hash(key) # 计算散列索引
        if self.hash_table[index] is None:
            # 若索引位置为空，则直接插入新节点
            self.hash_table[index] = Node(key, value)
        else:
            current = self.hash_table[index]
            while current.next:
                current = current.next
            current.next = Node(key, value)
    def search(self, key):
        """
        在散列表中查找给的定键的值
        """
        index = self._hash(key) # 计算散列索引
        current = self.hash_table[index]
        while current:
            if current.key == key:
                return current.value # 返回键对应的值
            current = current.next
        return None # 键不存在于散列表中
# 创建一个大小为 10 的散列表
hash_table = ChainingHashTable(10)

# 向散列表中插入键值对
hash_table.insert(5, 100)
hash_table.insert(15, 200)
hash_table.insert(25, 300)

# 查找键对应的值
print("Value for key 5:", hash_table.search(5))  # 输出: 100
print("Value for key 15:", hash_table.search(15))  # 输出: 200
print("Value for key 25:", hash_table.search(25))  # 输出: 300
print("Value for key 10:", hash_table.search(10))  # 输出: None (键不存在)
