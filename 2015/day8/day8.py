
def calculate_sizes(line):
    line = line.strip()
    code_size = len(line)
    line = line[1:-1] # removed quotes

    string_size = len(line)
    code_str = code_str_to_str(line)
    string_size = len(code_str)
    #print(code_str)
    return code_size, string_size

def code_str_to_str(code_str):
    i = 0
    new_str = ""
    while i < len(code_str):
        if code_str[i] == '\\':
            # hex number
            if code_str[i+1] == 'x':
                new_str += chr(int(code_str[i+2:i+4], 16))
                i+=3
            elif code_str[i+1] == '\\':
                new_str += '\\'
                i+=1
            # if next_str is not a hex or \ just ignore the backslash
        else:
            new_str += code_str[i]
        i += 1

    return new_str

def test(test_lines):

    for line in test_lines:
        print(line, calculate_sizes(line))

TEST_LINES = [
        '""',
        '"abc"',
        '"aaa\\"aaa"',
        '"\\x27"',
        '"mxvlz\\"fwuvx\\"cyk\\""'
]

if __name__ == "__main__":

    diff_size = 0
    with open("input.txt") as f:
        for line in f.readlines():
            code_size, str_size = calculate_sizes(line)
            diff_size += code_size - str_size

    print(diff_size)

