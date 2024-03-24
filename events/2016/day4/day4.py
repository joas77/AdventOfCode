import collections
import string
import re

def checksum(words):
    letter_freq = calculate_letter_freq(words)
    sorted_count_freq = sort_letter_freq(letter_freq)
    return "".join([letter for _, letter in sorted_count_freq])[0:5]

def calculate_letter_freq(words):
    letter_freq = collections.defaultdict(int)
    for word in words:
        for c in word:
            letter_freq[c] += 1

    return letter_freq

def sort_letter_freq(letter_freq: dict):
    count_letter = zip(letter_freq.values(), letter_freq.keys())
    return sorted(count_letter, key=lambda t: (-t[0], t[1]) )

def get_encrypted_names():
    with open("input.txt") as f:
        for line in f.readlines():
            yield line.strip()

################## FUCNTIONS FOR PART 2

def decrypt(msg: str, sector_id: int)->str:

    decoded = map( lambda c : decode_char(c, sector_id), msg)
    return "".join(decoded)

def decode_char(c: str, sector_id: int)->str:
    if c == "-":
        return " "
    ALFABET = string.ascii_lowercase
    alfabet_size = len(ALFABET)
    return ALFABET[(char_pos(c) + sector_id) % alfabet_size]


def char_pos(c: str)->int:
    return ord(c) - ord("a")

###################################33
if __name__ == "__main__":
    # examples:
    encrypted_names = [
        "aaaaa-bbb-z-y-x-123[abxyz]",
        "a-b-c-d-e-f-g-h-987[abcde]",
        "not-a-real-room-404[oarel]",
        "totally-real-room-200[decoy]"
    ]

    encrypted_names = get_encrypted_names()
    
    real_rooms_sum_ids = 0
    for name in encrypted_names:
        matches = name.split("-")
        words = matches[:-1]
        sector_id_and_checksum = matches[-1]
        sector_id, curr_checksum = sector_id_and_checksum.split("[")
        sector_id = int(sector_id)
        curr_checksum = curr_checksum.strip("]")
        calculated_checksum = checksum(words)

        if calculated_checksum == curr_checksum:
            print(f"{name} is a real room")
            real_rooms_sum_ids += sector_id
            room_name = "-".join(words)
            print(f"{room_name} ===> {decrypt(room_name, sector_id)}")
            print("=================")

    print(f"Sum of sector IDs of the real rooms = {real_rooms_sum_ids}")
        