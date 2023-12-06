def is_gear(part, part_pos, schematic):
    r, c = part_pos
    if part == "*":
        adj_parts_count = 0
        # sides
        adj_parts_count += 1 * schematic[r][c-1].isdigit() + 1 * schematic[r][c+1].isdigit()

        # up and down
        adj_parts_count += 1 * check_digits_up(schematic, part_pos)
        adj_parts_count += 1 * check_digits_down(schematic, part_pos)

        if adj_parts_count >= 2:
            return True

    return False

def check_digits_up(schematic, part_pos):
    r, c = part_pos

    if r > 0:
        for i in range(c-1, c+2):
            if schematic[r-1][i].isdigit():
                return True
    return False

def check_digits_down(schematic, part_pos):
    r, c = part_pos

    if r < len(schematic[0]) - 1:
        for i in range(c-1, c+2):
            if schematic[r + 1][i].isdigit():
                return True
    return False


if __name__ == "__main__":

    with open("input.txt") as f:
        schematic = [ line.strip() for line in f.readlines() ]

    gear_count = 0
    for r, row in enumerate(schematic):
        for c, part in enumerate(row):
            if is_gear(part, (r, c), schematic):
                print(part)
                gear_count += 1

    print(f"gears found: {gear_count}")