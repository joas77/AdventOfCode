from day3 import istriangle

if __name__ == "__main__":
    filepath = "input.txt"

    sidesa = []
    sidesb = []
    sidesc = []

    with open(filepath) as f:
        triangles = 0
        for l in f.readlines():
            a, b, c = [int(d) for d in l.strip().split()]
            sidesa.append(a)
            sidesb.append(b)
            sidesc.append(c)
    
    sides = sidesa + sidesb + sidesc