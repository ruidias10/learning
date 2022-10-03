import threading
import time
from queue import Queue
from random import randint

"""
maxsize - Number of items allowed in the queue.
empty() - Return True if the queue is empty, False otherwise.
full() - Return True if there are maxsize items in the queue. If the queue was initialized with maxsize=0 (the default), then full() never returns True.
get() - Remove and return an item from the queue. If queue is empty, wait until an item is available.
get_nowait() - Return an item if one is immediately available, else raise QueueEmpty.
put(item) - Put an item into the queue. If the queue is full, wait until a free slot is available before adding the item.
put_nowait(item) - Put an item into the queue without blocking. If no free slot is immediately available, raise QueueFull.
qsize() - Return the number of items in the queue.
"""


def producer(queue, data):
    for i in data:
        queue.put(i)
        s = randint(0, 10)
        print(f"  => Producer {i}", flush=True)
        time.sleep(s)


def consumer(queue):
    work_cycles = 0
    while True:
        if queue.qsize() == 0:
            time.sleep(1)
            work_cycles += 1

            if work_cycles == 20:
                print("  => End consumer working", flush=True)
                return None

        else:
            work_cycles = 0
            value = queue.get()
            print(f"  => Consumer {value}", flush=True)
            queue.task_done()
            time.sleep(1)


if __name__ == '__main__':
    print("Start program", flush=True)

    q = Queue()
    intdata = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
    strdata = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l']

    threads = [
        threading.Thread(target=producer, args=(q, intdata)),
        threading.Thread(target=producer, args=(q, strdata)),
        threading.Thread(target=consumer, args=(q,))
    ]

    [th.start() for th in threads]
    print(" Add threads to pool")

    [th.join() for th in threads]  # wait end of thread
    print(" End threads")
