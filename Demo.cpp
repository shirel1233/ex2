/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

//#include "Graph.hpp"
//5083
//cohen.shirel098@gmail.com
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
//#include <vector>
using namespace std;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.
    cout << "The graph g1 is : " << endl; 

    g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    vector<vector<int>> g3 = g1+(g2);
    ariel::Graph g5;// Add the two graphs together.
    g5.loadGraph(g3);
    cout << "The graph g1+g2 is : " << endl; 

    g5.printGraph();           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1*(-2);        // Multiply the graph by -2.
    cout << "Multiply the graph by -2: " << endl; 
    g1.printGraph(); // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    //g1*(-1);
    vector<vector<int>> g4 = g1*(g2);
    ariel::Graph g7;
    g7.loadGraph(g4);
     cout << "Multiply the two graphs together: " << endl; 
     // Multiply the two graphs together.
    g7.printGraph();           // Should print the multiplication of the matrices of g1 and g2: [-2, 0, -4], [-2, -6, -2], [-2, 0, 0-4]

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g6;
    g5.loadGraph(graph2); // Load the graph to the object.
    try
    {
        vector<vector<int>> g8 = g6*(g1); // Multiply the two graphs together.
        ariel::Graph g9;
        g9.loadGraph(g8);
        g9.printGraph();  
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }
}
