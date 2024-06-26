/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

//5083
//cohen.shirel098@gmail.com
#include "Algorithms.hpp"
using ariel::Algorithms;
#include <iostream>
#include <stdexcept>
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
    cout<<g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.
    cout << "The graph g2 is : " << endl; 
    cout<<g2; 

    ariel:: Graph g3(3);
    g3 = g1+g2;
    cout << "The graph g1+g2 is : " << endl; 
    cout<<g3;              // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1*(-2);        // Multiply the graph by -2.
    cout << "Multiply the graph g1 by -2: " << endl; 
    cout<<g1; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    ariel::Graph g4=g1*(g2);
     cout << "Multiply the two graphs g1 * g2 together: " << endl; 
     // Multiply the two graphs together.
    cout<<g4;           // Should print the multiplication of the matrices of g1 and g2: [-2, 0, -4], [-2, -6, -2], [-2, 0, 0-4]

    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g5;
    g5.loadGraph(graph2); // Load the graph to the object.
    try
    {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }
}
