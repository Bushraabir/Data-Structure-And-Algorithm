// Introduction to Graphs
// ----------------------------------------------------------
// Problem: Understand the basic concepts, types, and
// conventions of graphs used in graph theory.
//
// Example:
// Consider nodes: 1, 2, 3, 4
// Undirected edge between 1 and 4 allows travel both ways:
// 1 ↔ 4
// Directed edge from 1 to 4 allows travel one way:
// 1 → 4
//
// ----------------------------------------------------------
// Graph Types
// ----------------------------------------------------------
// 1. Undirected Graph:
//    - Edges have no arrows.
//    - Travel possible in both directions.
//    - Example: 1 ↔ 4
//
// 2. Directed Graph (Digraph):
//    - Edges have arrows indicating direction.
//    - Travel only allowed in the arrow's direction.
//    - Bi-directional edges possible using two separate edges.
//    - Example: 1 → 4 and 4 → 1 (separate edges)
//
// ----------------------------------------------------------
// Graph Conventions and Terminology
// ----------------------------------------------------------
// 1. Cycle:
//    - Path that starts and ends at the same node.
//    - Graph with at least one cycle → cyclic graph.
//    - No cycles → acyclic graph.
//    - DAG = Directed Acyclic Graph.
//
// 2. Path:
//    - Sequence of connected nodes via edges.
//    - Node cannot appear twice in the same path.
//    - Example: 1-2-3-5 is valid if edges exist.
//
// 3. Degree in Undirected Graph:
//    - Number of edges attached to a node.
//    - Property: sum of all degrees = 2 × number of edges.
//
// 4. Degree in Directed Graph:
//    - In-degree: number of incoming edges.
//    - Out-degree: number of outgoing edges.
//
// 5. Edge Weights:
//    - Numerical value on each edge (cost, distance, time).
//    - Default weight = 1 if unspecified.
//
// ----------------------------------------------------------
// Summary:
// ----------------------------------------------------------
// - Graphs consist of nodes and edges.
// - Types: Undirected, Directed.
// - Properties: Cycle, path, degree, weights.
// - Directed graphs have in-degree & out-degree.
// - Weighted edges represent additional information.
