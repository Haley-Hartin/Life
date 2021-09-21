/*!
This file contains definitions of the grid class.
*/

#ifndef GRID_H
#define GRID_H

#include <QGraphicsItem>
#include <vector>
#include "cell.h"
using namespace std;

class Grid {

public:

    Grid(int rows, int cols);  // constructor
    int get_population(){return live_cells_;} //inline fucntion

    //methods to convert cells position in plotwindow class to position in grid class
    int ConvertHeight(int height);
    int ConvertWidth(int width);

    void TakeTurn();
    void CalculateNextTurnStatus(int neighbors, Cell *c);
    void GetCellStatus(int row, int col);

    void addCell(Cell *c, int width, int height);
    Cell* getCell(int row, int col);
    void UpdateCellColor(QColor c);

    //methods to calculate number of live neighbors for a cell
    int get_bottom_neighbor(int row, int col);
    int get_top_neighbor(int row, int col);
    int get_left_neighbor(int row, int col);
    int get_right_neighbor(int row, int col);
    int get_bottom_left_neighbor(int row, int col);
    int get_bottom_right_neighbor(int row, int col);
    int get_top_left_neighbor(int row, int col);
    int get_top_right_neighbor(int row, int col);



private:
  int rows_;
  int cols_;
  int live_cells_ = 0;
  Cell *grid_[10][20];

};  // class Grid



#endif // Grid_H
