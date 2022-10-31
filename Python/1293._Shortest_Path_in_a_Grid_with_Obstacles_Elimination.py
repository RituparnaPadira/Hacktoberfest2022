def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        # x, y, obstacles, steps
        q = deque([(0, 0, k, 0)])
        seen = set()
             
        while q:
            x, y, left, steps = q.popleft()
            if (x,y,left) in seen or left < 0:
                continue

            if (x, y) == (m - 1, n - 1):
                return steps

            seen.add((x, y, left))
            if grid[x][y]: left -= 1

            for dx, dy in directions:
                new_x, new_y = x + dx, y + dy
                if 0 <= new_x < m and 0 <= new_y < n:
                    q.append((new_x, new_y, left, steps + 1))

        return -1
