from day2 import *

def find_min_game(game):
    min_game = {
        "red" : 0,
        "green": 0,
        "blue": 0
    }

    for game_set in game:
        for color, count in game_set.items():
            if min_game[color] < count:
                min_game[color] = count

    return min_game

def power_of_cubes(set_cubes):
    power = 1
    for count in set_cubes.values():
        power *= count

    return power

if __name__ == "__main__":
    with open("input.txt") as f:
        sum_min_game_power = 0
        for line in f.readlines():
            print(line)
            game = parse_game(line.strip())
            min_game = find_min_game(game)
            print(min_game)
            sum_min_game_power += power_of_cubes(min_game)

        print(f"power of sum of minimum games = {sum_min_game_power}")