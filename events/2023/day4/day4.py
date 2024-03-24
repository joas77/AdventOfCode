import functools

def parse(line):
    _, nums = line.split(":")
    winning_nums, nums_obtained = nums.strip().split("|")

    return set(int(n) for n in winning_nums.strip().split()), \
        set(int(n) for n in nums_obtained.strip().split())

def winning_nums(line):
    win_nums, nums =  parse(line)

    return win_nums & nums

def sum_points(points, winning_nums):
    card_score = 2 ** (len(winning_nums) - 1) if len(winning_nums) > 0 else 0
    return card_score + points

if __name__ == "__main__":
    with open("input.txt") as f:
        result = functools.reduce(
            sum_points,
            [winning_nums(line.strip()) for line in f.readlines()], 0)
        print(result)
