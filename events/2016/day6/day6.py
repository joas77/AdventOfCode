import collections

def get_max_freq(freq: dict) -> int:
    s = sorted(freq.items(), key= lambda item : item[1], reverse=True)
    return s[0][0]

if __name__ == "__main__":
    inputfile = "input.txt"

    TOTAL_COLS = 8 #6
    char_counters = [collections.defaultdict(int) for i in range(TOTAL_COLS)]
    with open(inputfile) as f:
        for line in f.readlines():
            for i, c in enumerate(line.strip()):
                char_counters[i][c] += 1


    print(char_counters)
    print("=====")

    message = ""
    for counter in char_counters:
        message+=get_max_freq(counter)

    print(message)