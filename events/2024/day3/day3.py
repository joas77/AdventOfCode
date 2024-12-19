import re
import functools

def solve_mult_inst(instrucion):
    return functools.reduce(lambda x,y: int(x)*int(y), re.findall(r"\d{1,3}", instrucion))

if __name__ == "__main__":
    input_file = "input.txt"

    with open(input_file) as input_data:
        memory = input_data.read()
        
        # instruction mul(X,Y), X, Y are 1-3 digits numbers
        instruction_pattern = re.compile(r"mul\(\d{1,3},\d{1,3}\)")

        instructions = instruction_pattern.findall(memory)
        result = sum(solve_mult_inst(ins) for ins in instructions)
        print(result)