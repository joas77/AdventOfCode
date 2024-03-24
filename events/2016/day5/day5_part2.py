import hashlib

def calculate_password_digit(door_id: str, index: int):
    md5_hex =""
    while md5_hex[0:5] != "00000":
        md5_hex = hashlib.md5(f"{door_id}{index}".encode("ascii")).hexdigest()
        index += 1

    print(f"found md5 hash = {md5_hex} with index = {index-1}")
    position, digit = md5_hex[5], md5_hex[6]
    return index, position, digit

if __name__ == "__main__":
    door_id = "ugkcyxxp"
    
    index = -1
    PASSWORD_SIZE = 8
    password = ["_"] * PASSWORD_SIZE
    digits_found = 0
    while digits_found < PASSWORD_SIZE:
        index, pos, d = calculate_password_digit(door_id, index + 1)
        if pos.isdigit() and 0 <= int(pos) < PASSWORD_SIZE:
            position = int(pos)
            if password[position] == "_":
                password[position] = d
                digits_found += 1
                print(f"password: {''.join(password)}")