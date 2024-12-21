import functools
import itertools
import operator

def next_debug(operators):
    def binary_op(x, y):
        f = next(operators)
        # if f == operator.add:
        #     print(f"{x} + {y}")
        # elif f == operator.mul:
        #     print(f"{x} * {y}")
        # print(f(x,y))
        return f(x, y)
    return binary_op

def concat(x, y):
    return int(f"{x}{y}")

def main():
    input_file = "input.txt" # input_test.txt
    is_part2 = True

    with open(input_file) as input_data:
        calibration_results = []
        for line in input_data.readlines():
            result, ops = line.strip().split(":")
            result = int(result.strip())
            operands = [int(op) for op in ops.strip().split()]

            print(f"{result} = {" ? ".join(map(lambda x: str(x), operands))}")

            operator_types = [operator.add, operator.mul]
            if is_part2:
                operator_types.append(concat)

            operators_comb = itertools.product(operator_types, repeat=len(operands)-1)

            for ops in operators_comb:
                possible_result = functools.reduce(next_debug(iter(ops)), operands)
                # print(possible_result)
                if possible_result == result:
                    print(possible_result)
                    calibration_results.append(possible_result)
                    break
        

        print(sum(calibration_results))

if __name__ == "__main__":
    main()