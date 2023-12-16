class LightMatrix:
    def __init__(self):
        self._lits = []
        self._on_count = 0

        for row in range(1000):
            self._lits.append( [ Light() for _ in range(1000)] )

    def traverse(self, position_from, position_to, command):
        row_from, col_from = position_from
        row_to, col_to = position_to

        for row in range(row_from, row_to + 1):
            for col in range(col_from, col_to + 1):
                prev_state = self._lits[row][col].is_on

                if command == "on":
                    self._lits[row][col].on()
                elif command == "off":
                    self._lits[row][col].off()
                elif command == "toggle":
                    self._lits[row][col].toggle()

                current_state = self._lits[row][col].is_on
                self._on_count += current_state - prev_state

    def on(self, position_from, position_to):
        self.traverse(position_from, position_to, "on")


    def off(self, position_from, position_to):
        self.traverse(position_from, position_to, "off")

    def toggle(self, position_from, position_to):
        self.traverse(position_from, position_to, "toggle")

    @property
    def lighted_count(self):
        return self._on_count

class Light:
    def __init__(self):
        self._is_on = False

    def on(self):
        self._is_on = True

    def off(self):
        self._is_on = True

    def toggle(self):
        self._is_on = not self._is_on

    @property
    def is_on(self):
        return self._is_on

def parse_instructions(file):
    with open(file) as f:
        for line in f.readlines():
            yield parse_instruction(line.strip())

def parse_instruction(line):
    l, r = line.split("through")

    l = l.strip()
    r = r.strip()

    if "on" in l:
        instruction = "on"
    elif "off" in l:
        instruction = "off"
    elif "toggle" in l:
        instruction = "toggle"
    else:
        print(f"Error parsing instruction {line}")

    from_str = l.split(" ")[-1]
    to_str = r
    from_point = tuple(map(int, from_str.split(",")))
    to_point = tuple(map(int, to_str.split(",")))

    return instruction, from_point, to_point


if __name__ == "__main__":

    lights = LightMatrix()
    lights.on((0,0), (2,2))

    print(f"lights on = {lights.lighted_count}")
    # lights.toggle((0,0), (999,0))
    # print(f"lights on = {lights.lighted_count}")

    # for ins, point_from, point_to in parse_instructions("input.txt"):
    #     lights.traverse(point_from, point_to, ins)

    # print(f"lights on = {lights.lighted_count}")