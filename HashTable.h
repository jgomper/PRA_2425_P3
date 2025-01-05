#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

private:
    int n; // Número de elementos almacenados actualmente
    int max; // Tamaño de la tabla hash
    ListLinked<TableEntry<V>>* table; // Array de listas enlazadas

    // Función hash
    int h(const std::string& key) {
        int ascii_sum = 0;
        for (char c : key) {
            ascii_sum += static_cast<int>(c);
        }
        return ascii_sum % max;
    }

public:
    // Constructor
    HashTable(int size) : n(0), max(size) {
        table = new ListLinked<TableEntry<V>>[max]; // Reserva dinámica
    }

    // Destructor
    ~HashTable() {
        delete[] table; // Liberar memoria dinámica
    }

    // Devuelve el número total de cubetas
    int capacity() const {
        return max;
    }

    // Sobrecarga del operador de salida
    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& th) {
        for (int i = 0; i < th.max; ++i) {
            out << "Cubeta " << i << ": ";
            for (const auto& entry : th.table[i]) {
                out << "[" << entry.key << " -> " << entry.value << "] ";
            }
            out << std::endl;
        }
        return out;
    }

    // Sobrecarga del operador []
    V operator[](const std::string& key) {
        int index = h(key);
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                return entry.value;
            }
        }
        throw std::runtime_error("Key not found");
    }

    // Otros métodos como insert(), search() y remove() se implementarán aquí,
    // haciendo uso de las operaciones proporcionadas por ListLinked<T>.
};

#endif
