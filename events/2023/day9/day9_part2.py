from day9 import *

def extrapolate_back(sequence):
    first_seq_nums = [sequence[0]]
    while not all_zero(sequence):
        sequence  = differences(sequence)
        first_seq_nums.append(sequence[0])

    print(first_seq_nums)

    prev_num = first_seq_nums.pop()
    while first_seq_nums:
        prev_num = first_seq_nums.pop() - prev_num

    print(prev_num)
    return prev_num

if __name__ == "__main__":
    input_file = "input.txt"

    seqs = parse_seqs(input_file)
    print(seqs)

    extrapolated_nums = [ extrapolate_back(s) for s in seqs ]
    print(f"extrapolated nums = {extrapolated_nums}")
    sum_extrapolated_nums = sum(extrapolated_nums)
    print(f"sum of extrapolated nums = {sum_extrapolated_nums}")