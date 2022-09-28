import os
import threading
import time
from random import randint


def counter(name, n):
    for n in range(1, n + 1):
        s = randint(0, 5)
        print(f" => {n} {name}(s)... sleep({s})")
        time.sleep(s)


def main():
    threads = [
        threading.Thread(target=counter, args=('Pato', 4)),
        threading.Thread(target=counter, args=('Galinha', 6)),
        threading.Thread(target=counter, args=('Elefante', 8)),
    ]

    [th.start() for th in threads]
    print(" => add threads to pool")

    [th.join() for th in threads]  # wait end of thread
    print(" => end threads")


if __name__ == '__main__':
    pid = os.getpid()
    print(f"Use: top -H -p {pid}")
    print(f"Use: pstree -a {pid}")
    main()
