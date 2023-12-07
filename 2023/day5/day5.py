def parse(f):
    parsing_seeds = True
    parsing_map = False
    seeds = []
    current_map_name = ""
    maps = {}
    for l in f.readlines():
        line = l.strip()
        if parsing_seeds:
            if "seeds" in line:
                seeds = parse_seeds(line)

        if "map" in line:
            parsing_map = True
            current_map_name = parse_map_name(line)
            continue
        elif line == "":
            parsing_map = False

        if parsing_map:
            source_dest_ranges = parse_map_range(line)
            if current_map_name in maps:
                maps[current_map_name].append(source_dest_ranges)
            else:
                maps[current_map_name] = [source_dest_ranges]

    return seeds, maps

def parse_seeds(seeds:str)->list:
    _, s = seeds.split(":")
    return [ int(seed) for seed in s.strip().split() ]

def parse_map_name(line:str):
    map_name, _  = line.split()
    return map_name

def parse_map_range(line:str):
    dest, source, _range = [int(n) for n in line.split()]
    return {
        "source" :      range(source, source + _range + 1),
        "destination":  range(dest, dest + _range + 1)
    }


def find_destination_in_map(seed, map_name, maps):
    dest = seed
    ranges = maps[map_name]

    for _range in ranges:
        source_range = _range["source"]
        dest_range = _range["destination"]

        if seed in source_range:
            diff = source_range.stop - seed
            dest = dest_range.stop - diff
            return dest

    return dest

maps_names = [
        "seed-to-soil",
        "soil-to-fertilizer",
        "fertilizer-to-water",
        "water-to-light",
        "light-to-temperature",
        "temperature-to-humidity",
        "humidity-to-location"
]

if __name__ == "__main__":
    file_input = "input.txt"
    with open(file_input) as f:
        seeds, maps = parse(f)

    print(f"seeds = {seeds}")

    locations = []
    # part 1
    for seed in seeds:
        location = seed
        for map_name in maps:
            location = find_destination_in_map(location, map_name, maps)
            print(f"location of seed {seed} in map {map_name} = {location}")

        locations.append(location)
        print("==========================")

    locations.sort()
    print(locations)

