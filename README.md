🗺️ Number of Countries in a Grid
📌 Problem Overview

You are given a rectangular map represented as a 2D matrix A of size N × M. Each cell in the matrix represents a square area painted with a specific color (integer value).

Two areas belong to the same country if:

They have the same color, and
They are connected orthogonally (up, down, left, right) through cells of the same color.

Your task is to compute the total number of distinct countries in the map.

🧠 Key Idea

This problem is essentially about counting connected components in a grid, where:

Each component consists of adjacent cells with the same value.
Movement is allowed only in 4 directions (no diagonals).
