#pragma once
#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
private:
    int row;
    int column;

public:
    bool operator==(Vertex V2) { return (this->row == V2.row && this->column == V2.column); }
    Vertex(int r = 0, int c = 0);
    int getRow() const;
    int getColumn() const;
    void setRow(int r);
    void setColumn(int c);
};

#endif // VERTEX_H
