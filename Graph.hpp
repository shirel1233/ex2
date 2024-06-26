//5083
//cohen.shirel098@gmail.com
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
class Graph{
    private:
    
    vector<vector<int>> mat;
    public:

    // Constructor
    Graph(size_t numVertices);
     Graph(){}
    // Destructor
    ~Graph();

    void loadGraph (const vector<vector<int>> matrix);
    void printGraph() const;
    size_t getNumVertices() const; 
    int getEdge(size_t i, size_t j) const;
    int getNumEdges() const;
    bool isDirected() const;
    void setEdge(size_t i, size_t j, int val);
    bool isContainedIn(const Graph& other) const;


    void operator+=(const Graph& other);
    void operator-=(const Graph& other);
    Graph operator+(const Graph& other) const;
    Graph operator-(const Graph& other) const;
    void operator+() const; // Unary +
    void operator-(); // Unary -

    bool operator>(const Graph& other) const;
    bool operator>=(const Graph& other) const;
    bool operator<(const Graph& other) const;
    bool operator<=(const Graph& other) const;
    bool operator==(const Graph& other) const;
    bool operator!=(const Graph& other) const;

    void operator++();    //++n
    void operator++(int); //n++
    void operator--();    //--n
    void operator--(int); //n--

    void operator*(int scalar);
    Graph operator*(const Graph& other) const;

    friend ostream& operator<<(ostream &os, const Graph& g) ; // Print Graph


};
}




