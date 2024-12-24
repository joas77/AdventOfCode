from collections import defaultdict
from itertools import combinations

class Vector2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, v):
        return Vector2D(self.x + v.x, self.y + v.y)

    def __sub__(self, v):
        return Vector2D(self.x - v.x, self.y - v.y)
    
    def __hash__(self):
        return hash((self.x, self.y))

    def __eq__(self, v):
        return self.x == v.x and self.y == v.y

    def __repr__(self):
        return str((self.x, self.y))


def is_inside_of_cuadrant(point, x_len, y_len):
    return 0 <= point.x <= x_len and 0 <= point.y <= y_len


def main():
    input_file = "input.txt" # input_test.txt

    with open(input_file) as input_data:
        antena_map = [l.strip() for l in input_data.readlines()]
    
    antena_types = defaultdict(list)
    for x, x_row in enumerate(antena_map):
        for y, val in enumerate(x_row):
            if val.isalnum():
                antena_types[val].append(Vector2D(x, y))

    print(antena_types)

    y_len = len(antena_map)
    x_len = len(antena_map[0])

    antinodes = set()
    for positions in antena_types.values():
        for a, b in combinations(positions, 2):
            d = a - b
            antinode1 = a + d
            antinode2 = b - d
            print(f"antinodes of pair {a} <--> {b} --  {antinode1} -- {antinode2}")
            if is_inside_of_cuadrant(antinode1, x_len, y_len):
                antinodes.add(antinode1)
            if is_inside_of_cuadrant(antinode2, x_len, y_len):
                antinodes.add(antinode2)

    print(antinodes)
    print(len(antinodes))


if __name__ == "__main__":
    main()