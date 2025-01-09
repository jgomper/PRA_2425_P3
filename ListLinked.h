#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;  // Puntero al primer nodo de la lista
    int n;           // Número de elementos en la lista

public:
    // Constructor
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* current = first;
        while (current != nullptr) {
            Node<T>* aux = current->next;
            delete current;
            current = aux;
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
        return out;
    }

    // Métodos heredados de List<T>
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Position out of range");
        }
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            current->next = new Node<T>(e, current->next);
        }
        ++n;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Position out of range");
        }
        Node<T>* toDelete;
        T data;
        if (pos == 0) {
            toDelete = first;
            data = toDelete->data;
            first = first->next;
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            toDelete = current->next;
            data = toDelete->data;
            current->next = toDelete->next;
        }
        delete toDelete;
        --n;
        return data;
    }

    T get(int pos) override {
        return (*this)[pos];
    }

    int search(T e) override {
        Node<T>* current = first;
        int index = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1;
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }
};

