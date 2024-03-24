from day6 import solve

# Time:        41     96     88     94
# Distance:   214   1789   1127   1055

if __name__ == "__main__":
    t = 41968894
    d = 214178911271055
    max_t, min_t = solve(t, d)
    ways_of_win = int(max_t) - int(min_t)
    print(max_t, min_t)
    print(ways_of_win)