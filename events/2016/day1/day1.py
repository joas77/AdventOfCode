import collections
class TaxiCabWalker:
    def __init__(self):
        # start pos
        self._direction = 1
        self._position = 0
        self._visit_tracker = collections.defaultdict(int)
        #self._visit_tracker[self._position] += 1

    def advance(self, ins):
        direction = ins[0]
        steps = int(ins[1:])
        print(f"advancing {steps} to {direction}...")

        if direction == "R":
            self._direction *= -1j
        elif direction == "L":
            self._direction *= 1j

        self._position += self._direction*steps
        self._visit_tracker[self.position] += 1

        visit_count = self._visit_tracker[self.position]
        if visit_count >= 2:
            print(f"position {self.position} visited {visit_count} times")
            print(f"we're {self.relative_pos} blocks away")

    @property
    def position(self):
        return self._position
    
    @property
    def relative_pos(self):
        return abs(self.position.real + self.position.imag)

def parse(file_data):
    return [ins.strip() for ins in file_data.strip().split(",")]



if __name__=="__main__":
    with open("input.txt") as f:
        instructions = parse(f.read())
        print(instructions)
        walker = TaxiCabWalker()
        for ins in instructions:
            walker.advance(ins)
        
        print(walker.position)
        #first part
        print(f"Walked {walker.relative_pos} blocks away")
