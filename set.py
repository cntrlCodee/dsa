class Set:
    def __init__(self, n):
        self.s = set()
        for i in range(n):
            e = int(input("Enter Element {}: ".format(i+1)))
            self.add(e)

    def __len__(self):
        return len(self.s)
    
    def __str__(self):
        return "\n{ " + " , ".join(str(e) for e in self.s) + " }\n"

    def __contains__(self, e):
        return e in self.s
    
    def __iter__(self):
        return iter(self.s)
        
    def add(self, e):
        self.s.add(e)

    def remove(self, e):
        self.s.discard(e)
    
    def search(self, e):
        if e in self.s:
            print("Present in Set.")
        else:
            print("Not present in Set.")

    def intersect(self, r):
        t = Set(0)
        t.s = self.s.intersection(r.s)
        return t
    
    def union(self, r):
        t = Set(0)
        t.s = self.s.union(r.s)
        return t
    
    def difference(self, r):
        t = Set(0)
        t.s = self.s.difference(r.s)
        return t
    
    def subset(self, r):
        return self.s.issubset(r.s)
    
    def properSubset(self, r):
        return self.subset(r) and not r.subset(self)


def main():
    n = int(input("Enter number of elements in set: "))
    s = Set(n)
    print(s)

    while True:
        print("\n1. Add element in set")
        print("2. Remove element from set")
        print("3. Check if element is in set")
        print("4. Size of set")
        print("5. Intersection of two sets")
        print("6. Union of two sets")
        print("7. Difference of two sets")
        print("8. Check if a set is a subset of another set")
        print("9. Check if a set is a proper subset of another set")
        print("10. Exit")
        choice = int(input("Enter choice:"))

        if choice == 1:
            e = int(input("Enter element to add: "))
            s.add(e)
            print(s)

        if choice == 2:
            e = int(input("Enter element to remove: "))
            s.remove(e)
            print(s)

        if choice == 3:
            e = int(input("Enter element to search for: "))
            s.search(e)
            
        if choice == 4:
            print("Set contains {} elements".format(len(s)))

        if choice == 5:
            r = Set(int(input("Enter number of elements in set B: ")))
            t = s.intersect(r)
            print("Set A =", s)
            print("Set B =", r)
            print("Intersection =", t)

        if choice == 6:
            r = Set(int(input("Enter number of elements in set B: ")))
            t = s.union(r)
            print("Set A =", s)
            print("Set B =", r)
            print("Union =", t)

        if choice == 7:
            r = Set(int(input("Enter number of elements in set B: ")))
            t = s.difference(r)
            print("Set A =", s)
            print("Set B =", r)
            print("Difference =", t)

        if choice == 8:
            r = Set(int(input("Enter number of elements in set B: ")))
            print("Set A =", s)
            print("Set B =", r)
            if s.subset(r):
                print("Set B is a subset of Set A")
            else:
                print("Set B is not a subset of Set A")

        if choice == 9:
            r = Set(int(input("Enter number of elements in set B: ")))
            print("Set A =", s)
            print("Set B =", r)
            if s.properSubset(r):
                print("Set B is a proper subset of Set A")
            else:
                print("Set B is not a proper subset of Set A")

        if choice == 10:
            exit()

main()
