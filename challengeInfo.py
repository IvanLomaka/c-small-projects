from collections import defaultdict
import heapq
import json

class Node:
    def __init__(self, id):
        self.id = id
        self.queues = defaultdict(list)  # Dictionary of queues for each connection
        self.tau_queue = []

    def add_queue(self, connection_id):
        self.queues[connection_id] = []

class Packet:
    def __init__(self, packet_id, path, start_time, size, travel_times, taus):
        self.id = packet_id
        self.path = path          # List of nodes in the path (e.g., ["R1", "R2", "A"])
        self.travel_times = travel_times  # Transmission times for each hop (ms)
        self.taus = taus          # Propagation delays for each hop (ms)
        self.current_hop = 0      # Index of the current node in the path
        self.start_time = start_time
        self.size = size
        self.total_time = 0.0       # Total time to reach destination
        self.time_on_node_left = 0  # Time left for transmission
        self.time_on_delay_left = 0 # Time left for propagation
        self.reached_destination = False

    def __repr__(self):
        return f"Packet({self.id})"  # Avoid comparing objects directly

class NetworkPathFinder:
    def __init__(self, network_config):
        self.graph = self._build_graph(network_config["links"])
        self.nodes = self._create_nodes(network_config["nodes"], network_config["links"])

    def _create_nodes(self, node_names, links):
        nodes = {name: Node(name) for name in node_names}
        for link in links:
            from_node = link["from"]
            to_node = link["to"]
            queue_id = self.get_queue_id(from_node, to_node)
            nodes[from_node].add_queue(queue_id)
            reverse_queue_id = self.get_queue_id(to_node, from_node)
            nodes[to_node].add_queue(reverse_queue_id)
        return nodes

    def _build_graph(self, links):
        graph = defaultdict(list)
        for link in links:
            graph[link["from"]].append((link["to"], link["tau"], link["capacity"]))
        return graph

    def get_queue_id(self, from_node, to_node):
        return f"From{from_node}To{to_node}"
    
    def find_path(self, start, end, size):
        # Priority queue to store (total_delay, current_node, path, travel_times, taus)
        queue = [(0, start, [], [], [])]
        visited = set()
        
        while queue:
            total_delay, current_node, path, travel_times, taus = heapq.heappop(queue)
            
            if current_node in visited:
                continue
            
            path = path + [current_node]
            visited.add(current_node)
            
            if current_node == end:
                return path, travel_times, taus
            
            for neighbor, delay, capacity in self.graph.get(current_node, []):
                if neighbor not in visited:
                    travel_time = (float(size) / capacity) * 1000 # Convert to microseconds
                    delay = delay * 1000 # Convert to microseconds
                    print(f"Current Node: {current_node}, Neighbor: {neighbor}, Travel Time: {travel_time}")
                    heapq.heappush(queue, (total_delay + delay, neighbor, path, travel_times + [travel_time], taus + [delay]))
        
        return [], [], []

def evaluateTime(packets, nodes):
    time = 0  # Current simulation time in ms

    # Initialize packets with start_time=0 to their starting node's queue
    for packet in packets:
        if packet.start_time == 0:
            current_node = nodes[packet.path[0]]
            queue_id = f"From{packet.path[0]}To{packet.path[1]}"
            current_node.queues[queue_id].append(packet)
            packet.time_on_node_left = packet.travel_times[0]

    while True:
        # Check if all packets have reached their destination
        all_reached = all(p.reached_destination for p in packets)
        if all_reached:
            break

        to_remove = []

        # Process propagation delays (tau_queue) first
        for node in nodes.values():
            for packet in node.tau_queue:
                packet.time_on_delay_left -= 1
                if packet.time_on_delay_left <= 0:
                    to_remove.append(packet)
                    packet.current_hop += 1
                    if packet.current_hop >= len(packet.path) - 1:
                        # Packet reached destination
                        packet.reached_destination = True
                        packet.total_time = time + 1  # Total time taken to reach destination
                    else:
                        # Move to next node's queue
                        next_node_id = packet.path[packet.current_hop]
                        next_node = nodes[next_node_id]
                        queue_id = f"From{packet.path[packet.current_hop]}To{packet.path[packet.current_hop + 1]}"
                        next_node.queues[queue_id].append(packet)
                        packet.time_on_node_left = packet.travel_times[packet.current_hop]

            # Remove processed packets from tau_queue
            for p in to_remove:
                if p in node.tau_queue:
                    node.tau_queue.remove(p)

        # Process transmission queues
        for node in nodes.values():
            for queue_id, queue in node.queues.items():
                if queue:
                    packet = queue[0]

                    if packet not in to_remove:
                        packet.time_on_node_left -= 1
                        if packet.time_on_node_left <= 0:
                            # if packet.id == "B1":
                            #     print(f"Packet {packet.id} reached {node.id} at time {(time + 1) / 1000}")
                            
                            # Move to propagation queue (tau_queue)
                            packet.time_on_delay_left = packet.taus[packet.current_hop]
                            node.tau_queue.append(packet)
                            queue.pop(0)  # Remove the packet from the queue

        time += 1  # Increment time after processing all events

# # Test paths with package sizes
# test_routes = [
#     ("P1", "A", "C", 375 * 8),
#     ("P2", "A", "D", 250 * 8),
#     ("P3", "A", "E", 375 * 8),
#     ("P4", "A", "F", 125 * 8),
#     ("P5", "A", "E", 375 * 8)
# ]

# network_config = {
#     "nodes": ["R1", "R2", "R3", "A", "B", "C", "D", "E", "F"],
#     "links": [
#         {"from": "A", "to": "R1", "capacity": 200, "tau": 20},
#         {"from": "R1", "to": "B", "capacity": 400, "tau": 20},
#         {"from": "R1", "to": "R2", "capacity": 250, "tau": 10},
#         {"from": "R2", "to": "C", "capacity": 1000, "tau": 50},
#         {"from": "R2", "to": "D", "capacity": 1000, "tau": 1},
#         {"from": "R2", "to": "R3", "capacity": 100, "tau": 5},
#         {"from": "R3", "to": "E", "capacity": 200, "tau": 1},
#         {"from": "R3", "to": "F", "capacity": 200, "tau": 1},
#         # Reverse links (assuming bidirectional communication)
#         {"from": "R1", "to": "A", "capacity": 200, "tau": 20},
#         {"from": "B", "to": "R1", "capacity": 400, "tau": 20},
#         {"from": "R2", "to": "R1", "capacity": 250, "tau": 10},
#         {"from": "C", "to": "R2", "capacity": 1000, "tau": 50},
#         {"from": "D", "to": "R2", "capacity": 1000, "tau": 1},
#         {"from": "R3", "to": "R2", "capacity": 100, "tau": 5},
#         {"from": "E", "to": "R3", "capacity": 200, "tau": 1},
#         {"from": "F", "to": "R3", "capacity": 200, "tau": 1}
#     ]
# }

test_routes = [
    ("A1", "A", "D", 9600),  # Packet A1 from A to R1
    ("A2", "A","D", 9600),  # Packet A2 from A to R1
    ("B1", "B", "D", 9600),  # Packet B1 from B to R1
    ("B2", "B", "D", 9600),  # Packet B2 from B to R1
    ("C1", "C", "B", 9600),  # Packet C1 from C to R2
]

network_config = {
    "nodes": ["R1", "R2", "A", "B", "C", "D"],
    "links": [
        {"from": "A", "to": "R1", "capacity": 8000, "tau": 1},   # 1 µs → 0.001 ms
        {"from": "B", "to": "R1", "capacity": 2000, "tau": 0.5}, # 0.5 µs → 0.0005 ms
        {"from": "R1", "to": "R2", "capacity": 4000, "tau": 0.5},# 0.5 µs → 0.0005 ms
        {"from": "C", "to": "R2", "capacity": 1000, "tau": 2},   # 2 µs → 0.002 ms
        {"from": "R2", "to": "D", "capacity": 24000, "tau": 3.5},# 3.5 µs → 0.0035 ms
        # Reverse links (bidirectional communication)
        {"from": "R1", "to": "A", "capacity": 8000, "tau": 1},
        {"from": "R1", "to": "B", "capacity": 2000, "tau": 0.5},
        {"from": "R2", "to": "R1", "capacity": 4000, "tau": 0.5},
        {"from": "R2", "to": "C", "capacity": 1000, "tau": 2},
        {"from": "D", "to": "R2", "capacity": 24000, "tau": 3.5}
    ]
}

# Example usage
config_json = json.dumps(network_config)
network_data = json.loads(config_json)
path_finder = NetworkPathFinder(network_data)

# Create packets based on the paths found by the algorithm
packets = []
for i, (id, start, end, package_size) in enumerate(test_routes):
    path, travel_times, taus = path_finder.find_path(start, end, package_size)
    if path:
        packet_id = id
        packet = Packet(packet_id, path, start_time=0, size=package_size, travel_times=travel_times, taus=taus)
        packets.append(packet)
        print(f"Packet {packet.id}: Path = {'->'.join(path)}, Travel Times = {packet.travel_times} Total Time = {packet.total_time:.2f} ms, Taus = {taus}")
    else:
        print(f"No path found from {start} to {end}")

# Evaluate the time taken for each packet to reach its destination
evaluateTime(packets, path_finder.nodes)

for packet in packets:
    print(f"Packet {packet.id}: Total Time = {packet.total_time / 1000} ms")

# Input data
# Time: ms !!
# Size: bits
# Capacity: kb/s