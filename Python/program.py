n = 5
# Upper half
for i in range(1, n + 1):
    print(" " * (n - i) + " ".join(str(j) for j in range(1, i + 1)))

# Lower half
for i in range(n - 1, 0, -1):
    print(" " * (n - i) + " ".join(str(j) for j in range(1, i + 1)))

print()