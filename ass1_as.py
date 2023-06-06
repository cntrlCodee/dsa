class LinearProbingHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * self.size
    
    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        while self.table[index] is not None:
            index = (index + 1) % self.size
        self.table[index] = (key, value)

    def search(self, key):
        index = self.hash_function(key)
        comparisons = 0
        while self.table[index] is not None:
            comparisons += 1
            if self.table[index][0] == key:
                return self.table[index][1], comparisons
            index = (index + 1) % self.size
        return None, comparisons

    def display(self):
        for index, item in enumerate(self.table):
            if item is not None:
                print(f"Index {index}: Key={item[0]}, Value={item[1]}")
            else:
                print(f"Index {index}: Empty")


class ChainingHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(self.size)]

    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        self.table[index].append((key, value))

    def search(self, key):
        index = self.hash_function(key)
        comparisons = 0
        for item in self.table[index]:
            comparisons += 1
            if item[0] == key:
                return item[1], comparisons
        return None, comparisons

    def display(self):
        for index, items in enumerate(self.table):
            print(f"Index {index}:")
            if items:
                for item in items:
                    print(f"  Key={item[0]}, Value={item[1]}")
            else:
                print("  Empty")


def linear_probing_menu():
    print("Linear Probing Hash Table")
    size = int(input("Enter the size of the hash table: "))
    hash_table = LinearProbingHashTable(size)

    while True:
        print("\n1. Insert a key-value pair")
        print("2. Search for a key")
        print("3. Display the hash table")
        print("4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            key = int(input("Enter the key: "))
            value = input("Enter the value: ")
            hash_table.insert(key, value)
            print("Key-value pair inserted successfully!")
        elif choice == 2:
            key = int(input("Enter the key to search: "))
            result, comparisons = hash_table.search(key)
            if result is not None:
                print("Search Result:", result)
                print("Number of Comparisons:", comparisons)
            else:
                print("Key not found!")
        elif choice == 3:
            hash_table.display()
        elif choice == 4:
            break
        else:
            print("Invalid choice! Please try again.")


def chaining_menu():
    print("Chaining Hash Table")
    size = int(input("Enter the size of the hash table: "))
    hash_table = ChainingHashTable(size)

    while True:
        print("\n1. Insert a key-value pair")
        print("2. Search for a key")
        print("3. Display the hash table")
        print("4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            key = int(input("Enter the key: "))
            value = input("Enter the value: ")
            hash_table.insert(key, value)
            print("Key-value pair inserted successfully!")
        elif choice == 2:
            key = int(input("Enter the key to search: "))
            result, comparisons = hash_table.search(key)
            if result is not None:
                print("Search Result:", result)
                print("Number of Comparisons:", comparisons)
            else:
                print("Key not found!")
        elif choice == 3:
            hash_table.display()
        elif choice == 4:
            break
        else:
            print("Invalid choice! Please try again.")


def main():
    while True:
        print("\n1. Linear Probing")
        print("2. Chaining")
        print("3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            linear_probing_menu()
        elif choice == 2:
            chaining_menu()
        elif choice == 3:
            break
        else:
            print("Invalid choice! Please try again.")


if __name__ == "__main__":
    main()

