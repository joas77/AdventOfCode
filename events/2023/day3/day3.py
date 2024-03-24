import re

def symbol_in_schematic(schematic_line:str):
    # .... is not a symbol
    not_symbol = "."*len(schematic_line)
    return not_symbol != schematic_line

def check_down(schematic, row_index, match_indexes):
    if row_index < len(schematic) - 1:
        s, e = match_indexes
        start = s - 1 if s - 1 >=0 else s
        row_size = len(schematic[0])
        end = e + 1 if s + 1 < row_size else e
        return symbol_in_schematic(schematic[row_index + 1][start:end])

    return False

def check_up(schematic, row_index, match_indexes):
    if row_index > 0:
        s, e = match_indexes
        start = s - 1 if s - 1 >=0 else s
        row_size = len(schematic[0])
        end = e + 1 if s + 1 < row_size else e
        return symbol_in_schematic(schematic[row_index - 1][start:end])

    return False

def check_sides(schematic, row_index, match_indexes):
    s, e = match_indexes
    found_symbol = False
    # left
    if s > 0:
        found_symbol = found_symbol or schematic[r_index][s-1] != "."

    row_size = len(schematic[0])
    if e < row_size:
        found_symbol = found_symbol or schematic[r_index][e] != "."

    return found_symbol



if __name__ == "__main__":

    with open("input.txt") as f:
        schematic = [ line.strip() for line in f.readlines() ]

    regex = re.compile(r"\d+")
    symbols = []
    for r_index, row in enumerate(schematic):
        for match in regex.finditer(row):
            match_indexes = ( match.start(0), match.end(0) )
            if check_down(schematic, r_index, match_indexes ) or \
                    check_up(schematic, r_index, match_indexes ) or \
                    check_sides(schematic, r_index,match_indexes):
                print(match.group(0))

                symbols.append(int(match.group(0)) )

print(f"Sum of symbosl {sum(symbols)}")