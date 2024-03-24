class TaxiCabPoint:
    def __init__(self, x: int = 0, y: int=0) -> None:
        self.x = x
        self.y = y

    def distance(self, tc_point):
        return abs(self.y - tc_point.y) + abs(self.x + tc_point.x)
    

class KeyPad:
    def __init__(self) -> None:
        """
        Repr of keypad with next shape
            1
          2 3 4
        5 6 7 8 9
          A B C
            D
        """
        self._keypad = {
            (0,2):   '1',
            (-0,1):  '2',
            (0,1):   '3',
            (1,1):   '4',
            (-2,0):  '5',
            (-1,0):  '6',
            (0,0):   '7',
            (1,0):   '8',
            (2,0):   '9',
            (-1,-1): 'A',
            (0,-1):  'B',
            (-1,-1): 'C',
            (0,-2):  'D',
        }
        self._pos = (-2,0)
        self._taxicab_radious = 2
        
    def press(self, cmd):
        x, y = self._pos
        if cmd == "U":
            y += 1
        elif cmd == "D":
            y -= 1
        elif cmd == "L":
            x -= 1
        elif cmd == "R":
            x += 1
        
        if self._is_pos_valid(x, y):
            self._pos = x, y

    def _is_pos_valid(self, x, y):
        tc_pos = TaxiCabPoint(x, y)
        center = TaxiCabPoint(0,0)
        return tc_pos.distance(center) <= self._taxicab_radious

    def get_num(self):
        return self._keypad[self._pos]

if __name__=="__main__":
    filepath = "input.txt"
    code = ""
    with open(filepath) as f:
        keypad = KeyPad()
        for l in f.readlines():
            line = l.strip()
            for c in line:
                keypad.press(c)
            
            print(keypad.get_num())
            code += str(keypad.get_num())

        print(f"bathroom code {code}")