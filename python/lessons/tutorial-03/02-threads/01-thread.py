import threading
import time


def counter(name, n):
    for n in range(1, n + 1):
        print(f" => {n} {name}(s)...")
        time.sleep(1)


def main():
    th = threading.Thread(target=counter, args=('Elefante', 10))

    th.start()
    print(" => add thread to pool")
    th.join()  # wait end of thread
    print(" => end thread")


if __name__ == '__main__':
    main()
