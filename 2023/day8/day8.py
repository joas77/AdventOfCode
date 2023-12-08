def parse(file):
    map_graph = {}
    with open(file) as f:
        for i, line in enumerate(f.readlines()):
            if i == 0:
                # instructions in first line
                instructions = line.strip()
            elif line.strip() != "":
                node, edges = line.strip().split("=")
                left, right = edges.strip().lstrip("(").rstrip(")").split(",")
                map_graph[node.strip()] = (left.strip(), right.strip())

    return instructions, map_graph


if __name__ == "__main__":
    input_file = "input.txt"
    instructions, map_graph = parse(input_file)

    steps = 0
    current_node = "AAA"
    while current_node != "ZZZ":
        for ins in instructions:
            if ins == "L":
                current_node = map_graph[current_node][0]
            elif ins == "R":
                current_node = map_graph[current_node][1]

            steps += 1

    print(map_graph[current_node])
    print(steps)