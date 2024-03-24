import day8

def count_chars_encoded(line):
    count = 0
    for c in line:
        if c == '"':
            count += 1
        elif c == '\\':
            count += 1
        count += 1

    count += 2 # for the quotes
    return count

def test(test_lines):
    for line in test_lines:
        print(line, count_chars_encoded(line))

if __name__ == "__main__":
    test(day8.TEST_LINES)
    with open("input.txt") as f:
        result = sum( count_chars_encoded(line.strip()) -  len(line.strip())
                for line in f.readlines()
            )

        print(result)