import collections

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
    #return sorted(letter_freq, key=lambda x : letter_freq[x], reverse=True)
    count_letter = zip(letter_freq.values(), letter_freq.keys())
    return sorted(count_letter, key=lambda t: (-t[0], t[1]) )

def get_encrypted_names():
    with open("input.txt") as f:
        for line in f.readlines():
            yield line.strip()

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
        curr_checksum = curr_checksum.strip("]")
        calculated_checksum = checksum(words)

        if calculated_checksum == curr_checksum:
            print(f"{name} is a real room")
            real_rooms_sum_ids += int(sector_id)
            print("=================")

    print(f"Sum of sector IDs of the real rooms = {real_rooms_sum_ids}")
        