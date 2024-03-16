from day3 import istriangle

if __name__ == "__main__":
    filepath = "input.txt"

    sidesa = []
    sidesb = []
    sidesc = []

    with open(filepath) as f:
        
        for l in f.readlines():
            a, b, c = [int(d) for d in l.strip().split()]
            sidesa.append(a)
            sidesb.append(b)
            sidesc.append(c)
    
    sides = sidesa + sidesb + sidesc
    triangles = 0
    for i in range(0, len(sides), 3):
        a, b, c = sides[i:i+3]
        if istriangle(a, b, c):
                print(f"found a triangle with sides {(a, b, c)}")
                triangles += 1
    
    print(f"total triangles found: {triangles}")