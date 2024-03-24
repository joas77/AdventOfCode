def istriangle(a, b, c):
    return a + b > c and a + c > b and b + c > a

if __name__ == "__main__":
    filepath = "input.txt"
    with open(filepath) as f:
        triangles = 0
        for l in f.readlines():
            a, b, c = [int(d) for d in l.strip().split()]

            if istriangle(a, b, c):
                print(f"found a triangle with sides {(a, b, c)}")
                triangles += 1
        print(f"total triangles found: {triangles}")
        