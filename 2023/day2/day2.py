def parse_game(game_str):
    sets = game_str.split(":")[1].split(";")
    return [ parse_game_set(s) for s in sets ]

def parse_game_set(gameset):
    gameset_map = {}
    for choice in gameset.split(","):
        numstr, color = choice.split()
        gameset_map[color] = int(numstr)

    return gameset_map

def is_game_possible(game, total_cubes:dict):
    for game_set in game:
        for color, count in game_set.items():
            if count > total_cubes[color]:
                return False

    return True

if __name__ == "__main__":
    with open("input.txt") as f:
        sum_games_ids = 0
        for gameid, line in enumerate(f.readlines(), start=1):
            #print(line)
            game = parse_game(line.strip())
            #print(game)
            if is_game_possible(game, {"red": 12, "green": 13, "blue": 14}):
                sum_games_ids += gameid


        print(f"result = {sum_games_ids}")
