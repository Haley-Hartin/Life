/*!
This file contains implementations of the grid class.
*/

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <QGraphicsItem>
#include <vector>
#include <QVector>

#include "grid.h"
#include "cell.h"

/*!
  \fn Grid(int x, int y)

    Constructor. Creates a grid to contain the cells
    Sets the rows and colums
    Initializes each index with a null cell.
*/
Grid::Grid(int x, int y) {
  rows_ = x;
  cols_ = y;
  Cell *c = NULL;

  for(int i=0; i<rows_; i++){
      for(int j =0; j<cols_; j++){
        grid_[i][j]=c;
      }
  }
}

/*!
  \fn Grid::addCell(Cell *c, int width, int height)

    Add a cell to the grid.
    Calculates the index to add the cell to
    Updates the number of live cells.
*/
void Grid::addCell(Cell *c, int width, int height){

    //get the index to add the cell to
  int new_width = ConvertWidth(width);
  int new_height = ConvertHeight(height);

  //add the cell
  grid_[new_height][new_width] = c;

  //update live_cells
  if(c->get_alive()){
      live_cells_+=1;
  }
}

/*!
  \fn Grid::UpdateCellColor(QColor c)

    Updates the cell color of the immortal cells.
*/
void Grid::UpdateCellColor(QColor c){
    for(int i=0; i<rows_; i++){
        for(int j =0; j<cols_; j++){
            if(grid_[i][j]->get_immortal()){
                 grid_[i][j] -> set_color(c);
            }

        }
    }

}

/*!
  \fn Grid::ConvertWidth(int width)

    Calculates the x index of the cell
*/
int Grid::ConvertWidth(int width){
  return width/67;
}

/*!
  \fn Grid::ConvertHeight(int Height)

    Calculates the y index of the cell
*/
int Grid::ConvertHeight(int height){
  return height/35;
}

/*!
  \fn Grid::getCell(int row, int col)

    Returns the cell at a given index.
*/
Cell* Grid::getCell(int row, int col){
    return grid_[row][col];
}


/*!
  \fn Grid::TakeTurn()

    Takes a step in the game.
    Loops through all the cells to calculate if the cell will be alive next round.
    Loops through all the cells and sets its current status to its next turn status.
    Tracks live cells.
*/
void Grid::TakeTurn(){
    live_cells_ = 0;

    //sets the next turn status
    for(int i=0; i<rows_; i++){
        for(int j =0; j<cols_; j++){
               GetCellStatus(i,j);

        }
    }

    //updates the current turn status
    for(int i=0; i<rows_; i++){
        for(int j =0; j<cols_; j++){
          //track live_cells
          if(grid_[i][j]->get_next_turn_status()== true){
              live_cells_+=1;
          }
          grid_[i][j]->setStatus(grid_[i][j]->get_next_turn_status());
        }
    }
}

/*!
  \fn Grid::GetCellStatus(int row, int col)

   Calculates the number of live nighbors a cell has.
*/
void Grid::GetCellStatus(int row, int col){

    int neighbors = 0;
    Cell *c = getCell(row, col);

    //compute the number of live neighbors
    neighbors += get_top_neighbor(row, col);
    neighbors += get_bottom_neighbor(row, col);
    neighbors += get_left_neighbor(row, col);
    neighbors += get_right_neighbor(row, col);
    neighbors += get_bottom_left_neighbor(row, col);
    neighbors += get_bottom_right_neighbor(row, col);
    neighbors += get_top_left_neighbor(row, col);
    neighbors += get_top_right_neighbor(row, col);

    CalculateNextTurnStatus(neighbors, c);
}

/*!
  \fn Grid::CalculateNextTurnStatus(int neighbors, Cell *c)

   Logic to determine if a cell will be alive or dead in the next round.
   Sets the cells next turn status.
*/
void Grid::CalculateNextTurnStatus(int neighbors, Cell *c){

    c->setNextTurnStatus(c->get_alive());

    //if the cell is immortal set its next turn status to alive
    if(c->get_immortal()){
        c->setNextTurnStatus(true);
    }
    //if the cell is alive
    else if(c->get_alive()){
        //set its next turn status to dead if it has less than two or more than 3 live neighbors
        if(neighbors<2 || neighbors > 3){
            c->setNextTurnStatus(false);
        }
    }
     //if the cell is dead  and has 3 live neighbors
    else if((!(c->get_alive())) && neighbors ==3){
        //set its next turn status to alive
        c->setNextTurnStatus(true);
    }
}

/*!
  \fn Grid::get_top_neighbor(int row, int col)

   Check if the top neighbor of a cell is alive or dead
*/
int Grid::get_top_neighbor(int row, int col){

    if(row-1<0){
        row = rows_-1;
    }
    else{
        row = row -1;
    }

    bool status = getCell(row, col)->get_alive();
    if(status){ return 1;}
    else{ return 0;}
}

/*!
  \fn Grid::get_bottom_neighbor(int row, int col)

   Check if the bottom neighbor of a cell is alive or dead
*/
int Grid::get_bottom_neighbor(int row, int col){

    if(row+1>=rows_){
        row = 0;
    }
    else{
        row = row + 1;
    }

    bool status = getCell(row, col)->get_alive();
    if(status){ return 1;}
    else{ return 0;}
}

/*!
  \fn Grid::get_right_neighbor(int row, int col)

   Check if the right neighbor of a cell is alive or dead
*/
int Grid::get_right_neighbor(int row, int col){

    if(col+1>=cols_){
        col = 0;
    }
    else{
        col = col + 1;
    }

    bool status = getCell(row, col)->get_alive();
    if(status){ return 1;}
    else{ return 0;}
}

/*!
  \fn Grid::get_left_neighbor(int row, int col)

   Check if the left neighbor of a cell is alive or dead
*/
int Grid::get_left_neighbor(int row, int col){

    if(col-1< 0){
        col = cols_-1;
    }
    else{
        col = col - 1;
    }

    bool status = getCell(row, col)->get_alive();
    if(status){ return 1;}
    else{ return 0;}
}

/*!
  \fn Grid::get_top_left_neighbor(int row, int col)

   Check if the top left neighbor of a cell is alive or dead
*/
int Grid::get_top_left_neighbor(int row, int col){

    if(col-1< 0){
        col = cols_-1;
    }
    else{
        col = col - 1;
    }

    if(row-1<0){
        row = rows_-1;
    }
    else{
        row = row -1;
    }

    bool status = getCell(row, col)->get_alive();
    if(status){ return 1;}
    else{ return 0;}
}

/*!
  \fn Grid::get_top_right_neighbor(int row, int col)

   Check if the top right neighbor of a cell is alive or dead
*/
int Grid::get_top_right_neighbor(int row, int col){

    if(col+1>= cols_ ){
        col = 0;
    }
    else{
        col = col + 1;
    }

    if(row-1<0){
        row = rows_-1;
    }
    else{
        row = row -1;
    }

    bool status = getCell(row, col)->get_alive();
    if(status){ return 1;}
    else{ return 0;}
}

/*!
  \fn Grid::get_bottom_right_neighbor(int row, int col)

   Check if the bottom right neighbor of a cell is alive or dead
*/
int Grid::get_bottom_right_neighbor(int row, int col){

    if(col+1>= cols_ ){
        col = 0;
    }
    else{
        col = col + 1;
    }

    if(row+1>= rows_){
        row = 0;
    }
    else{
        row = row + 1;
    }

    bool status = getCell(row, col)->get_alive();
    if(status){ return 1;}
    else{ return 0;}
}

/*!
  \fn Grid::get_bottom_left_neighbor(int row, int col)

   Check if the bottom left neighbor of a cell is alive or dead
*/
int Grid::get_bottom_left_neighbor(int row, int col){

    if(col-1<0 ){
        col = cols_-1;
    }
    else{
        col = col - 1;
    }

    if(row+1>=rows_){
        row = 0;
    }
    else{
        row = row + 1;
    }

    bool status = getCell(row, col)->get_alive();
    if(status){ return 1;}
    else{ return 0;}
}




