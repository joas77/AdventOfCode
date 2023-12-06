import math
# as input.txt is really simple I preferred
# hand-code the values on the code
# Time:        41     96     88     94
# Distance:   214   1789   1127   1055

def solve(tmax, s):
    squared = math.sqrt(tmax*tmax - 4 * s)/2
    max_t = tmax/2 + squared
    min_t = tmax/2 - squared

    return max_t, min_t

if __name__ == "__main__":
    time_distance_values = [
        (41, 214), (96, 1789), (88, 1127), (94, 1055)
    ]

    mult = 1
    for t, d in time_distance_values:
        max_t, min_t = solve(t, d)
        ways_of_win = int(max_t) - int(min_t)
        mult *= ways_of_win
        print(f"{max_t}, {min_t} => ways of win = {ways_of_win}")

    print(f"multiplication fo ways of winning = {mult}")