#include "doctest.h"
#include "Algorithms.hpp"
#include <sstream>
//5083
//cohen.shirel098@gmail.com

using namespace std;



TEST_CASE("Test graph addition") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;

    std::ostringstream oss;
    oss << g3;
    std::string result = oss.str();
    std::string expected = "{0, 2, 1}, \n{2, 0, 3}, \n{1, 3, 0}\n\n";  // Adjust to match the format of operator<< output

    CHECK(result == expected);
}


TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g4 = g1*g2;
    std::ostringstream oss;
    oss << g4;
    std::string result = oss.str();
    std::string expected = "{0, 0, 2}, \n{1, 0, 1}, \n{1, 0, 0}\n\n";  // Adjust to match the format of operator<< output

    CHECK(result == expected);
}

TEST_CASE("Test constructor and loadGraph") {
    ariel::Graph g1(3);
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    std::ostringstream oss;
    oss << g1;
    std::string result = oss.str();
    std::string expected = "{0, 1, 0}, \n{1, 0, 1}, \n{0, 1, 0}\n\n";

    CHECK(result == expected);
}
TEST_CASE("Test graph subtraction") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 - g2;

    std::ostringstream oss;
    oss << g3;
    std::string result = oss.str();
    std::string expected = "{0, 0, -1}, \n{0, 0, -1}, \n{-1, -1, 0}\n\n";

    CHECK(result == expected);
}
TEST_CASE("Test unary ++ operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ++g1;

    std::ostringstream oss;
    oss << g1;
    std::string result = oss.str();
    std::string expected = "{0, 2, 1}, \n{2, 0, 2}, \n{1, 2, 0}\n\n";

    CHECK(result == expected);
}

TEST_CASE("Test unary -- operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    --g1;

    std::ostringstream oss;
    oss << g1;
    std::string result = oss.str();
    std::string expected = "{0, 0, -1}, \n{0, 0, 0}, \n{-1, 0, 0}\n\n";

    CHECK(result == expected);
}

TEST_CASE("Test scalar multiplication") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    g1 * 3;

    std::ostringstream oss;
    oss << g1;
    std::string result = oss.str();
    std::string expected = "{0, 3, 0}, \n{3, 0, 3}, \n{0, 3, 0}\n\n";

    CHECK(result == expected);
}

TEST_CASE("Test graph equality operator") {
    ariel::Graph g1(3);
    std::vector<std::vector<int>> graph1 = {
        {0, 1},
        {1, 0},
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
}

TEST_CASE("Test graph inequality operator") {
    ariel::Graph g1(3);
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1.isContainedIn(g2));
    CHECK(g2.isContainedIn(g1));

    CHECK(g1 != g2);
}

TEST_CASE("Test graph less than operator") {
    ariel::Graph g1(4);
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0, 2},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    std::vector<std::vector<int>> graph2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1 > g2);
}


TEST_CASE("Test graph containment: Smaller graph contained in larger graph") {
    ariel::Graph g1(2);
    std::vector<std::vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1.isContainedIn(g2));
}

TEST_CASE("Test graph addition with cycle preservation") {
    // Create a graph with a cycle
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    g1.loadGraph(graph1);

    // Check if g1 has a cycle before addition
    CHECK(ariel::Algorithms::isContainsCycle(g1) == 1);

    // Create another graph with a cycle
    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(graph2);

    // Check if g2 has a cycle before addition
    CHECK(ariel::Algorithms::isContainsCycle(g2) == 1);

    // Perform graph addition
    ariel::Graph g3 = g1 + g2;

    // Check if g3 has a cycle after addition
    CHECK(ariel::Algorithms::isContainsCycle(g3) == 1);
}
TEST_CASE("Test graph multiplication and shortest path") {
    // Create a graph for multiplication
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    g1.loadGraph(graph1);

    // Create another graph for multiplication with compatible dimensions
    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 0, 0},
        {0, 0, 0},
        {-1, 1, 0}
    };
    g2.loadGraph(graph2);

    // Perform graph addition
    ariel::Graph g3 = g1 + g2;

    // Verify shortest path from vertex 0 to vertex 2 in g3
    std::vector<int> shortestPath = ariel::Algorithms::shortestPath(g3, 0, 2);
    
    // Define the expected shortest path
    std::vector<int> expectedPath = {0, 1, 2};
    
    // Check if the calculated shortest path matches the expected path
    CHECK(shortestPath == expectedPath);
}

TEST_CASE("Test isDirected() function for directed graph") {
    // Create a directed graph
    ariel::Graph g;
    std::vector<std::vector<int>> directedGraph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}
    };
    g.loadGraph(directedGraph);

    // Check if the graph is detected as directed
    CHECK(g.isDirected() == true);
}

TEST_CASE("Test isDirected() function for undirected graph") {
    // Create an undirected graph
    ariel::Graph g;
    std::vector<std::vector<int>> undirectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(undirectedGraph);

    // Check if the graph is detected as undirected
    CHECK(g.isDirected() == false);
}

TEST_CASE("Test isBipartite and mult") {

    // Create the graph
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    g1.loadGraph(graph1);

    // Perform graph multiplication
    g1 * 2;
    vector<vector<int>> expected1 = {{0, 2}, {1, 3}};
    CHECK(ariel::Algorithms::isBipartite(g1) == expected1);
    
}

