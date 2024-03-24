def parse_seqs(file):
    seqs = []
    with open(file) as f:
        for line in f.readlines():
            nums_str = line.strip().split()
            seqs.append( [int(num_str) for num_str in nums_str ] )

    return seqs

def extrapolate(sequence):
    last_seq_nums = [sequence[-1]]
    while not all_zero(sequence):
        print(sequence)
        sequence  = differences(sequence)
        last_seq_nums.append(sequence[-1])

    print(last_seq_nums)

    next_num = last_seq_nums.pop()
    while last_seq_nums:
        next_num += last_seq_nums.pop()
        print(next_num)

    return next_num

def differences(seq):
    return [ second - first for first, second in zip( seq[0:len(seq) - 1], seq[1::]) ]

def all_zero(seq):
    for z in seq:
        if z != 0:
            return False

    return True

if __name__ == "__main__":
    input_file = "input.txt"

    seqs = parse_seqs(input_file)
    print(seqs)

    sum_extrapolated_nums = sum(extrapolate(s) for s in seqs)
    print(f"sum of extrapolated nums = {sum_extrapolated_nums}")