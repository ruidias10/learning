import sys

print(123)
print("Rui", "Dias")
print("Rui", "Dias", sep="-")
print("Rui", "Dias", sep="-", end="!")
print()

# 824.176.070-18
print("824", "176", "070", sep=".", end="-")
print("18")
print()

# raw
print(r"Print something on the \n screen!")
print()

# format
print(f"Print operating system version: {sys.version}")
print(f"Print operating system info: {sys.version_info}")
print()

# repeat
print(20 * "A")
print("A" * 20)
print()