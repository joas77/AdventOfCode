

if __name__ == "__main__":
    with open("input.txt") as f:
        sum_ = 0
        for line in f.readlines():
            num = 0
            for c in line:
                if c.isdigit():
                    num += int(c)*10
                    break

            for c in reversed(line):
                if c.isdigit():
                    num += int(c)
                    #print(num)
                    break

            sum_ += num

        print(sum_)