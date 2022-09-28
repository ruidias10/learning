import time
from queue import Queue
from threading import Thread

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


def createProducer(queue):
    for i in range(1, 20):
        queue.put(i)
        print(f"  => Producer {i}", flush=True)
        time.sleep(2)


def createConsumer(queue):
    while queue.qsize() > 0:
        value = queue.get()
        print(f"  => Consumer {value}", flush=True)
        queue.task_done()
        time.sleep(1)


if __name__ == '__main__':
    print("Start program", flush=True)
    q = Queue()

    th1 = Thread(target=createProducer, args=(q,))
    th2 = Thread(target=createConsumer, args=(q,))

    th1.start()
    th1.join()

    th2.start()
    th2.join()
