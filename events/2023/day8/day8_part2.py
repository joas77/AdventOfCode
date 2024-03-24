from day8 import parse

def find_start_nodes(map_graph):
    return [node for node in map_graph if node[2] == "A"]

def are_end_nodes(nodes:list)->bool:
    return sum([n[2]=="Z" for n in nodes]) == len(nodes)

if __name__ == "__main__":
    input_file = "input.txt"
    instructions, map_graph = parse(input_file)


    nodes = find_start_nodes(map_graph)
    print(nodes)
    node = nodes[0]

    node_steps = []
    for node in nodes:
        steps = 0
        while node[2]!="Z":
            for ins in instructions:
                node = map_graph[node][0] if ins=="L" else map_graph[node][1]
                steps += 1
        node_steps.append(steps)

    print(node_steps)
    # TODO calculate LCM of node_steps
