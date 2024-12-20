from enum import StrEnum

class Orientation(StrEnum):
    UP = "^"
    DOWN = "v"
    LEFT = "<"
    RIGHT = ">"

class GuardWalker:
    def __init__(self, lab_map:list[list]):
        self._lab_map = lab_map
        self._total_rows = len(self._lab_map)
        self._total_cols = len(self._lab_map[0])
        self._current_pos = self.find_position(self._lab_map)
        self._transition_table = {
            Orientation.UP      : Orientation.RIGHT,
            Orientation.RIGHT   : Orientation.DOWN,
            Orientation.DOWN    : Orientation.LEFT,
            Orientation.LEFT    : Orientation.UP
        }
    
    @property
    def currentpos(self):
        return self._current_pos

    @staticmethod
    def find_position(lab_map:list[list]):
        for i, row in enumerate(lab_map):
            for j, pos in enumerate(row):
                if pos == Orientation.UP:
                    return (i,j)
        
        return (0,0)
    
    def is_at_edge(self):
        r, c = self.currentpos
        return r >= self._total_rows - 1 or c >= self._total_cols - 1 or r == 0 or c == 0 
    
    def turn_right(self):
        r, c = self.currentpos
        new_orientation = self._transition_table[self.orientation]
        self._lab_map[r][c] = new_orientation.value

    @staticmethod
    def _is_obstacle(val:str):
        return val == "#"
    
    @property
    def orientation(self):
        r,c = self.currentpos
        return Orientation(self._lab_map[r][c])

    def step(self):
        if not self.is_at_edge():
            orientation = self.orientation
            
            r, c = self.currentpos
            if orientation == Orientation.UP:
                nextpos = r - 1, c
            elif orientation == Orientation.DOWN:
                nextpos = r + 1, c
            elif orientation == Orientation.LEFT:
                nextpos = r, c - 1
            elif orientation == Orientation.RIGHT:
                nextpos = r, c + 1

            next_cell_val = self._lab_map[nextpos[0]][nextpos[1]]

            if self._is_obstacle(next_cell_val):
                self.turn_right()
            else:
                # step forward
                self._lab_map[r][c] = "."
                r, c = nextpos
                self._current_pos = nextpos
                self._lab_map[r][c] = orientation.value
            
    def print(self):
        for row in self._lab_map:
            print("".join(row))    

if __name__ == "__main__":
    input_file = "input_test.txt"
    lab_map = []
    with open(input_file) as input_data:
        lab_map = [list(line.strip()) for line in input_data.readlines()]

    guard_walker = GuardWalker(lab_map)

    unique_positions = set()
    unique_positions.add(guard_walker.currentpos)

    while not guard_walker.is_at_edge():
        guard_walker.step()
        guard_walker.print()
        print()
        unique_positions.add(guard_walker.currentpos)

    print(len(unique_positions))