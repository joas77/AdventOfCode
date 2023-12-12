STAR = "#"

def parse_expanded_galaxy(file, space_expansion=1):
    galaxy_positions = []
    row_size = 0
    with open(file) as f:
        y = 0
        x_positions = set()
        for line in f.readlines():
            row_size = len(line) # TODO do this only once
            x = 0
            row = line.strip()
            if STAR not in row:
                y +=  space_expansion
            else:
                # get star position
                for x in get_start_x_positions(row):
                    galaxy_positions.append((x,y))
                    x_positions.add(x)

            y += 1

    galaxy_positions.sort()
    print(galaxy_positions)
    x_prev = 0
    space_inc = 0
    for i, galaxy in enumerate(galaxy_positions):
        galaxy_x, galaxy_y = galaxy
        # test all values between x and x_prev
        for x in range(x_prev, galaxy_x):
            if x not in x_positions:
                # increase space
                space_inc += space_expansion

        new_x = galaxy_x + space_inc
        galaxy_positions[i] = new_x, galaxy_y
        x_prev = galaxy_x

    return galaxy_positions

def get_start_x_positions(row):
    x = row.find(STAR)
    while x != -1:
        yield x
        x = row.find(STAR, x+1)

def taxicab_distance(p1, p2):
    x1,y1 = p1
    x2,y2 = p2
    return abs(y2 - y1) + abs(x2 - x1)

if __name__ == "__main__":
    file_input = "test_input.txt"
    galaxy_map = parse_expanded_galaxy(file_input, 10)
    print(galaxy_map)

    sum_distances = 0
    pairs_count = 0
    for i, star1 in enumerate(galaxy_map[0:-1], 1):
        for start2 in galaxy_map[i:]:
            pairs_count += 1
            d = taxicab_distance(star1, start2)
            print(f"pair {pairs_count} distance between {star1} and {start2} = {d}")
            sum_distances += d

    print(f"sum of distances = {sum_distances}")