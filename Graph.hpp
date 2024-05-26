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
    using IndexType= typename std:: vector<int>::size_type;

    void loadGraph (const vector<vector<int>> matrix);
    void printGraph() const;
    int getNumVertices() const; 
    int getEdge(IndexType i, IndexType j) const;
    int getNumEdges() const;
    bool isDirected() const;
    bool isContainedIn(const Graph& other) const;

    void operator+=(const Graph& other);
    void operator-=(const Graph& other);
    vector<vector<int>> operator+(const Graph& other) const;
    vector<vector<int>> operator-(const Graph& other) const;
    void operator+() const; // Unary +
    void operator-(); // Unary -

    bool operator>(const Graph& other) const;
    bool operator>=(const Graph& other) const;
    bool operator<(const Graph& other) const;
    bool operator<=(const Graph& other) const;
    bool operator==(const Graph& other) const;
    bool operator!=(const Graph& other) const;

    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);

    void operator*(int scalar);
    vector<vector<int>> operator*(const Graph& other) const;

};
}
