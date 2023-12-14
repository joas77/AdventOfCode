import itertools
import collections

def rule_one(line:str)->bool:
    pairs = {}
    for i, w in enumerate(sliding_window(line, 2)):
        if w in pairs:
            if i - 1 != pairs[w]["index"]: # no overlapping
                # increase count
                pairs[w]["count"] += 1
        else:
            pairs[w] = {"index": i, "count": 1}

    for v in pairs.values():
        if v["count"] > 1:
            return True

    return False

def rule_two(line:str)->bool:
    for window in sliding_window(line, 3):
        if window[0] == window[2]:
            return True
    return False

def sliding_window(iterable, n):
    # sliding_window('ABCDEFG', 4) --> ABCD BCDE CDEF DEFG
    it = iter(iterable)
    window = collections.deque(itertools.islice(it, n-1), maxlen=n)
    for x in it:
        window.append(x)
        yield tuple(window)

if __name__ == "__main__":
    input_file = "input.txt"

    with open(input_file) as f:
        nice_strings = sum(rule_one(line.strip()) and rule_two(line.strip()) for line in f)

    print(f"nice strings = {nice_strings}")

