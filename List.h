#ifndef LIST_H
#define LIST_H

#include <stdexcept>

// Clase abstracta pura y genérica List<T>
template <typename T>
class List {
public:
    // Inserta el elemento e en la posición pos
    virtual void insert(int pos, T e) = 0;

    // Inserta el elemento e al final de la lista
    virtual void append(T e) = 0;

    // Inserta el elemento e al principio de la lista
    virtual void prepend(T e) = 0;

    // Elimina y devuelve el elemento situado en la posición pos
    virtual T remove(int pos) = 0;

    // Devuelve el elemento situado en la posición pos
    virtual T get(int pos) = 0;

    // Devuelve la posición de la primera ocurrencia del elemento e, o -1 si no se encuentra
    virtual int search(T e) = 0;

    // Indica si la lista está vacía
    virtual bool empty() = 0;

    // Devuelve el número de elementos de la lista
    virtual int size() = 0;

    // Destructor virtual puro
    virtual ~List() = default;
};

#endif

