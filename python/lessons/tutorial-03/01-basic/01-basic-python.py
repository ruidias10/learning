import datetime
import math


def main():
    start_process = datetime.datetime.now()
    processing(end=50_000_000)
    process_duration = datetime.datetime.now() - start_process
    print(f"Duration: {process_duration.total_seconds()} seconds.")


def processing(end, start=1):
    pos = start
    factor = 1000 * 1000

    while pos < end:
        math.sqrt((pos - factor) * (pos - factor))
        pos += 1


if __name__ == '__main__':
    main()

"""
Duration 12.238526 seconds.
"""
