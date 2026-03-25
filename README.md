# 🗺️ Number of Countries in a Grid (C++ BFS Solution)

## 📌 Overview

This project solves the problem of counting the number of **distinct countries** in a grid-based map.

Each cell in a 2D matrix represents a colored area. A **country** is defined as a group of **orthogonally connected cells (up, down, left, right)** that share the same color.

---

## 🧠 Approach

This solution uses **Breadth-First Search (BFS)** to identify and count connected components in the grid.

### 🔍 Key Idea

- Traverse every cell in the matrix.
- If a cell has not been visited:
  - It represents a **new country**.
  - Start a BFS to explore all connected cells with the same color.
  - Mark all those cells as visited.

---

## ⚙️ Algorithm Steps

1. Initialize a `visited` matrix to track explored cells.
2. Loop through each cell `(i, j)`:
   - If not visited:
     - Increment country count.
     - Start BFS from `(i, j)`.
3. During BFS:
   - Explore 4 directions (up, down, left, right).
   - Add neighbors with the same color to the queue.
4. Continue until all cells are processed.

---

## 💻 Implementation

- Language: **C++**
- Data Structures Used:
  - `vector` for grid and visited tracking
  - `queue` for BFS traversal

---

## ⏱️ Complexity Analysis

| Type              | Complexity |
|------------------|-----------|
| Time Complexity   | **O(N × M)** |
| Space Complexity  | **O(N × M)** |

- Each cell is visited exactly once.
- BFS ensures efficient exploration of connected regions.

---

## 🧪 Test Cases

Included test cases cover:

- ✅ Standard example (expected output: `11`)
- ✅ All cells same color → `1 country`
- ✅ All cells different → each cell is its own country
- ✅ Single cell edge case

---

## ▶️ Example Output

```bash
Result:        11  (expected 11)
All same:      1   (expected 1)
All different: 4   (expected 4)
Single cell:   1   (expected 1)
```

---

## 🚀 How to Run

```bash
g++ solution.cpp -o solution
./solution
```

---

## 📚 Concepts Covered

- Graph traversal (BFS)
- Connected components in a grid
- Matrix traversal
- Queue-based exploration

---

## 💡 Notes

- BFS is used instead of DFS to avoid recursion depth issues for large grids.
- The solution efficiently handles up to **300,000 cells** as required by constraints.

---

## 🔮 Possible Improvements

- Use **DFS (recursive or iterative)** as an alternative
- Optimize space using **in-place marking**
- Extend to support **diagonal connections**
