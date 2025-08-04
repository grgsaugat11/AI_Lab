A_capacity = 4
B_capacity = 3
goal = 2

visited = set()
steps = []

def get_successors(state):
    a, b = state
    successors = []

    successors.append((A_capacity, b))
    successors.append((a, B_capacity))
    successors.append((0, b))
    successors.append((a, 0))
    pour = min(b, A_capacity - a)
    successors.append((a + pour, b - pour))
    pour = min(a, B_capacity - b)
    successors.append((a - pour, b + pour))

    return successors

queue = [((0, 0), [])]

while queue:
    (a, b), path = queue.pop(0)

    if a == goal:
        steps = path + [(a, b)]
        break

    if (a, b) in visited:
        continue

    visited.add((a, b))

    for new_state in get_successors((a, b)):
        if new_state not in visited:
            queue.append((new_state, path + [(a, b)]))

if steps:
    print("Solution to get 2L in Jug A:")
    for i, (a, b) in enumerate(steps):
        print(f"Step {i}: Jug A = {a}L, Jug B = {b}L")
else:
    print("No solution found.")