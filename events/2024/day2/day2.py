def diff(data):
    diffs = []
    for i in range(1, len(data)):
        diffs.append(data[i] - data[i-1])

    return diffs


if __name__ == "__main__":
    reports = []
    input_file = "input.txt"
    with open(input_file) as input_data:
        for line in input_data.readlines():
            reports.append([int(c) for c in line.strip().split()])

    safe_reports_count = 0

    for report in reports:
        diffs = diff(report)
        minimum = min(diffs)
        maximum = max(diffs)

        range_dec = range(-3, 0)
        range_inc = range(1, 4)

        if (minimum in range_inc and maximum in range_inc) or\
            (minimum in range_dec and maximum in range_dec):
            safe_reports_count += 1 

            print(f"{report} is safe")


    print(safe_reports_count)
