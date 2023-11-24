value = "3113322113"


def look_and_say(integer:str)->str:
    result = ""
    digit_count = 1
    for i in range(len(integer)-1):
        digit_current = integer[i]
        digit_next = integer[i+1]
        if digit_current == digit_next:
            digit_count += 1
        else:
            result += f"{digit_count}{digit_current}"
            digit_count = 1

    # last digit
    result += f"{digit_count}{integer[-1]}"

    return result

if __name__ == "__main__":
    print(look_and_say("111221"))
    print(look_and_say("1"))
    print(look_and_say("21"))
    print(look_and_say("1211"))

    val = "3113322113"
    for i in range(40):
        val = look_and_say(val)

    print(f"result ==> {len(val)}")