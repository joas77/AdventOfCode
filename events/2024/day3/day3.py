import re
import functools

def solve_mult_inst(instrucion):
    return functools.reduce(lambda x,y: int(x)*int(y), re.findall(r"\d{1,3}", instrucion))

if __name__ == "__main__":
    input_file = "input.txt"
    is_part2 = True
    with open(input_file) as input_data:
        memory = input_data.read()
        
        # instruction mul(X,Y), X, Y are 1-3 digits numbers
        instruction_pattern = re.compile(r"mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\)")

        instructions = instruction_pattern.findall(memory)
        enabled = True
        result = 0
        for ins in instructions:
            if "mul" in ins and enabled:
                result += solve_mult_inst(ins)
            elif is_part2 and "don't" in ins:
                enabled = False
            elif is_part2 and ins == "do()":
                enabled = True

        print(result)
        