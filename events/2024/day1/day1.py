from collections import defaultdict

def listtohist(data):
    hist = defaultdict(int)
    for e in data:
        hist[e] +=  1

    return hist


if __name__ == "__main__":
    locations_ids_left = []
    locations_ids_right = []
    with open("input.txt") as input_data:
        for line in input_data.readlines():
            l, r = [int(n) for n in line.strip().split()]
            locations_ids_left.append(l)
            locations_ids_right.append(r)

    locations_ids_left.sort()
    locations_ids_right.sort()

    result = sum(abs(l-r) for l, r in zip(locations_ids_left, locations_ids_right))

    # part 1
    print("part 1 result")
    print(result)

    locations_ids_right_hist = listtohist(locations_ids_right)

    result_part2 = sum([l*locations_ids_right_hist[l] for l in locations_ids_left if l in locations_ids_right])

    print("part 2 result")
    print(result_part2)