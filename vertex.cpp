#include "Vertex.h"

Vertex::Vertex(int r, int c) : row(r), column(c) {}

int Vertex::getRow() const {
    return row;
}

int Vertex::getColumn() const {
    return column;
}

void Vertex::setRow(int r) {
    row = r;
}

void Vertex::setColumn(int c) {
    column = c;
}
