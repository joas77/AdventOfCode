import hashlib

def calculate_password_digit(door_id: str, index: int):
    md5_hex =""
    while md5_hex[0:5] != "00000":
        md5_hex = hashlib.md5(f"{door_id}{index}".encode("ascii")).hexdigest()
        index += 1

    print(f"found md5 hash = {md5_hex}")
    return index, md5_hex[5] #6th character

if __name__ == "__main__":
    door_id = "ugkcyxxp"
    
    index = -1
    password = ""
    for i in range(8):
        index, d = calculate_password_digit(door_id, index + 1)
        password += d

    print(f"password: {password}")