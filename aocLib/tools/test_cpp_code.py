import unittest
import pathlib
import subprocess

def compile(path: pathlib.Path):
    build_folder = path/"build"
    build_folder.mkdir(exist_ok=True)
    # call cmake build commands
    cmake = "cmake"
    ret_code = subprocess.run([cmake, "-DCMAKE_BUILD_TYPE=Debug", build_folder]).returncode
    if ret_code == 0:
        ret_code = subprocess.run([cmake, "--build", build_folder ]).returncode

    return ret_code

class TestSolutions(unittest.TestCase):
    def test_compile(self):
        aoc_events_path = "../../events/"
        for file_path in pathlib.Path(aoc_events_path).rglob("solutions.cpp"):
            day_path = file_path.parent
            print(day_path)
            self.assertEqual(compile(day_path), 0, "Compilation error")

        self.assertTrue(True)

if __name__ == "__main__":
    unittest.main()