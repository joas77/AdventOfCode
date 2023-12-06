import regex as re

def clean_matches(matches):
    mix_nums = []
    for match in matches:
        for r in match:
            if r!= "":
                mix_nums.append(r)

    return mix_nums

def letter2num(str_digit:str):
    if str_digit.isdigit():
        return str_digit

    return str(STRNUM2NUM[str_digit])

STRNUM2NUM = {
    "one": 1,
    "two": 2,
    "three": 3,
    "four": 4,
    "five": 5,
    "six": 6,
    "seven": 7,
    "eight": 8,
    "nine": 9,
}

if __name__ == "__main__":
    pattern = re.compile(r"(\d)|(one)|(two)|(three)|(four)|(five)|(six)|(seven)|(eight)|(nine)")
    with open("input.txt") as f:
        sum_ = 0
        for line in f.readlines():
            matches = pattern.findall(line, overlapped=True)
            digits_str = clean_matches(matches)

            first_digit = letter2num(digits_str[0])
            last_digit =  letter2num(digits_str[-1]) if digits_str else ''

            num_str = first_digit + last_digit
            print(line, num_str)
            sum_ += int(num_str)

        print(sum_)
