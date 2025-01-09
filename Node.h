#include <ostream>

template <typename T>
class Node {
public:
    T data;                // Elemento almacenado en el nodo
    Node<T>* next;         // Puntero al siguiente nodo (nullptr si es el último)

    // Constructor
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    // Sobrecarga del operador << para imprimir el nodo
    friend std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
        out << node.data;
        return out;
    }
};

