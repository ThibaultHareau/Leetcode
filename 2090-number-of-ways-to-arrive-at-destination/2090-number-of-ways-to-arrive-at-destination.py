class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for origin, target, time in roads:
            graph[origin].append((target, time))
            graph[target].append((origin, time))
            
        distances = [float('inf') for i in range(n)]
        ways = [0 for i in range(n)]

        distances[0] = 0
        ways[0] = 1
        
        unexplored = [(0, 0)]
        
        MODULO = 10**9 + 7
        
        # Dijkstra's algorithm
        while unexplored:
            d, node = heapq.heappop(unexplored)
            
            if d > distances[node]:
                continue
                
            for neighbor, time in graph[node]:
                if distances[node] + time < distances[neighbor]:
                    distances[neighbor] = distances[node] + time
                    ways[neighbor] = ways[node]
                    heapq.heappush(unexplored, (distances[neighbor], neighbor))
                elif distances[node] + time == distances[neighbor]:
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MODULO
        
        return ways[n-1]