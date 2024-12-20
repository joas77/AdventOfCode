import subprocess
import argparse
from pathlib import Path

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="utility to setup AoC Startup files")
    parser.add_argument("year")
    parser.add_argument("day")
    parser.add_argument("directory")
    parser.add_argument("--lang",  default="cpp")

    args = parser.parse_args()

    year = args.year
    day = args.day
    path = args.directory
    lang = args.lang
    
    print(f"configuring folder {path}/{year}/{day} ...")

    path = f"{path}/{year}/day{day}"
    templates_path = Path.cwd()/f"templates/{lang}"

    cmds = [
        f"mkdir -p {path}",
    ]

    if lang == "cpp":
        cmds.append(f"mkdir -p {path}/build")
        # TODO replace aoc20XXDayXX in cmake by teh year an day

    for cmd in cmds:
        subprocess.run(cmd.split())

    # copy templates
    for template in templates_path.iterdir():
        subprocess.run(["cp", template, path])
