//5083
//cohen.shirel098@gmail.com
#include "Graph.hpp"
#include <stdexcept>
using namespace std;


// Constructor that initializes the matrix with zeros
ariel::Graph::Graph(size_t numVertices) : mat(numVertices, vector<int>(numVertices, 0)) {
    // mat is initialized to an numVertices x numVertices matrix with all zeros
}

// Destructor
ariel::Graph::~Graph() {
    // No need to explicitly delete anything, since we're using std::vector
}

void ariel::Graph::loadGraph(const vector<vector<int>> matrix) {
    if (matrix.size() != matrix[0].size()) {
        throw std::invalid_argument("Error: matrix is not square.");
    }
    // Copy the input matrix
    mat = matrix;
    // Ensure the diagonal elements are zero
    for (size_t i = 0; i < mat.size(); ++i) {
        mat[i][i] = 0;
    }     
}

size_t ariel::Graph::getNumVertices() const {
    size_t n = mat.size();
    return n;
};


// Helper function to check if the graph is directed
bool ariel::Graph::isDirected() const {
    // Check if the matrix is symmetric for undirected graphs
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = i + 1; j < mat[i].size(); j++) {
            if (mat[i][j] != mat[j][i]) {
                return true; // directed
            }
        }
    }
    return false; // undirected
};

int ariel::Graph:: getNumEdges() const {
    int numEdges = 0;
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = i + 1; j < mat[i].size(); j++) {
            if (mat[i][j] != 0) {
                // For directed graphs, count all non-zero values
                numEdges++;
            
            }
        }
    }
    // For undirected graphs, divide by 2 since each edge is counted twice
    if (!isDirected()) {
        numEdges /= 2;
    }
    return numEdges;
}

void ariel::Graph:: setEdge(size_t i, size_t j, int val){
    if (i >= mat.size() || j >= mat.size()) {
        cerr << "Error: Invalid indices." << endl;
        return; // Return some default value indicating error
    }
    if(i!=j){
        mat[i][j]=val;
    }else{
        mat[i][j]=0;
    }
}

int ariel::Graph::getEdge(size_t i, size_t j)const {
    // Check if indices are valid
    if (i >= mat.size() || j >= mat.size()) {
        cerr << "Error: Invalid indices." << endl;
        return -1; // Return some default value indicating error
    }

    // Return the value at the specified indices in the adjacency matrix
    int ans = mat[i][j];
    return ans;
};

void ariel::Graph::printGraph() const {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j];
            if (j != mat[i].size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}


bool ariel::Graph::isContainedIn(const Graph& other) const {
    // Check if *this is larger than other
    if (mat.size() > other.mat.size() || mat[0].size() > other.mat[0].size()) {
        return false; // *this cannot be contained in other if it's larger in size
    }

    if (*this == other) { 
        return false;  // Graphs are identical, so *this is not contained in other
    } 

    // Check if the adjacency matrix of *this is a submatrix of other's adjacency matrix
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] != 0 && other.mat[i][j] == 0) {
                return false;  // *this has an edge that other does not have
            }
        }
    }
    return true;  // *this is contained within other
}

void ariel::Graph:: operator+=(const Graph& other) {
    if (mat.size() != other.mat.size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for addition.");
    }
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j] += other.mat[i][j];
            }
            
        }
    }
}

void ariel::Graph::operator-=(const Graph& other) {
    if (mat.size() != other.mat.size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for subtraction.");
    }
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j] -= other.mat[i][j];
            }
            
        }
    }
}

ariel:: Graph ariel::Graph::operator+(const Graph& other) const {
    Graph result(mat.size());
    if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for addition.");
    }
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            result.setEdge(i,j, mat[i][j] + other.mat[i][j]);
        }
    }

    return result;
}

ariel:: Graph ariel::Graph::operator-(const Graph& other) const {
    Graph result(mat.size());
    if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
        throw std::invalid_argument("Error: Matrices must have same dimensions for subtraction.");
    }
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            result.setEdge(i,j, mat[i][j] - other.mat[i][j]);
        }
    }
    return result;
}

// Unary operator (+)
void ariel::Graph::operator+() const {
}
// Unary operator (-)
void ariel::Graph::operator-() {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            mat[i][j] = -mat[i][j];
        }
    }
}

void ariel::Graph::operator++() {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                ++mat[i][j];
            }
        }
    }
}

void  ariel::Graph::operator--() {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                --mat[i][j];
            }
        }
    }
}

void ariel::Graph::operator--(int) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j]--;
            }
        }
    }
}
 void ariel::Graph::operator++(int) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j]++;
            }
        }
    }
}

void ariel::Graph:: operator*(int scalar) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
            mat[i][j]= mat[i][j]*scalar;
            }
        }
    }
}

ariel::Graph ariel::Graph::operator*(const Graph& other) const {
    if (mat.size() != other.mat.size() || mat[0].size() != other.mat[0].size()) {
        throw std::invalid_argument("Error: Matrices must have the same dimensions for multiplication.");
    }

    size_t n = mat.size();
    Graph result(n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            int sum = 0;
            for (size_t k = 0; k < n; ++k) {
                sum += mat[i][k] * other.mat[k][j];
            }
            result.setEdge(i, j, sum);
        }
    }

    return result;
}



bool ariel::Graph::operator==(const Graph& other) const {
    if (mat.size() != other.mat.size()) {
        // Graphs G1 and G2 will be called equal if they are of the same order of magnitude
        return false;
    }

    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            // Check if corresponding edges are equal
            if (mat[i][j] != other.mat[i][j]) {
                return false;
            }
        }
    }

    // Additional condition: Compare using > and < operators
    if (*this > other || *this < other) {
        return false;
    }

    return true;
}

bool ariel::Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}


bool ariel::Graph:: operator<(const Graph& other) const {
    // Check if G1 is directly contained in G2
    if (isContainedIn(other)) {
        return true;
    }
    // Check if G2 is directly contained in G1
    else if (other.isContainedIn(*this)) {
        return false;
    }
    // If neither graph is directly contained in the other
    else {
        // Compare the number of edges
        int numEdges1 = getNumEdges();
        int numEdges2 = other.getNumEdges();
        if (numEdges1 != numEdges2) {
            return numEdges1 < numEdges2;
        }
        // If the number of edges is the same, compare the order of magnitude of the adjacency matrices
        else {
            return mat.size() < other.mat.size();
        }
    }
}

        
bool ariel::Graph::operator>(const Graph& other) const {
    // Implement > using the < operator
    return other < *this;
}

bool ariel::Graph::operator>=(const Graph& other) const {
    // Implement >= using > and ==
    return (*this > other) || (*this == other);;
}

bool ariel::Graph::operator<=(const Graph& other) const {
    // Implement <= using < and ==
    return (*this < other) || (*this == other);
}



ostream &ariel::operator<<(ostream &os, const Graph &g)
{
    size_t n = g.mat.size();
    size_t m = g.mat[0].size();

    for (size_t i = 0; i < n; i++)
    {
        os << "{";
        for (size_t j = 0; j < m; j++)
        {
            os << g.mat[i][j];
            if (j != m - 1)
            {
                os << ", ";
            }
        }
        os << "}";
        if (i != n - 1)
        {
            os << ", ";
        }
        os << "\n";
    }
    os << "\n";
    return os;
}


