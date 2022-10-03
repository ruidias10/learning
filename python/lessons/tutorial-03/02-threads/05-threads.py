from concurrent.futures import thread
import threading
import time

start = time.perf_counter()


def do_samething(secounds):
    print(f"Sleeping {secounds} secound(s)...")
    time.sleep(secounds)
    print("Done Sleeping...")


"""
t1 = threading.Thread(target=do_samething)
t2 = threading.Thread(target=do_samething)

t1.start()
t2.start()

t1.join()
t2.join()
"""

threads = []

for _ in range(10):
    t = threading.Thread(target=do_samething, args=[1.5])
    t.start()
    threads.append(t)

for thread in threads:
    thread.join()


finish = time.perf_counter()

print(f"Finished in {round(finish-start, 3)} secound(s)")

#gsettings set org.gnome.shell.extensions.dash-to-dock background-opacity 0
#gsettings reset org.gnome.shell.extensions.dash-to-dock background-opacity