class KeyPad:
    def __init__(self) -> None:
        self._keypad = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        self._pos = (1,1)
        self._total_rows = len(self._keypad)
        self._total_cols = len(self._keypad[0])
        
    def press(self, cmd):
        r, c = self._pos
        if cmd == "U":
            r -= 1
        elif cmd == "D":
            r += 1
        elif cmd == "L":
            c -= 1
        elif cmd == "R":
            c += 1
        
        if self._is_pos_valid(r, c):
            self._pos = r, c

    def _is_pos_valid(self, row, col):
        return (0 <= row < self._total_rows ) and \
            (0 <= col < self._total_cols)

    def get_num(self):
        r, c = self._pos
        return self._keypad[r][c]

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