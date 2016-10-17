# fillit - the smallest square finder!

##developed by: Zackary Smith & Arthur Zhuk

_fillit_ is project that allows for searching for the optimal
solution among a large set of tetrimino piece possibilities.
fillit features an algorithm which fits tetriminos together
into the smallest possible square grid.

A **tetrimino** is a 4 block geometric figure as found in the game
Tetris.
![alt text](https://github.com/ug02fast/fillit/blob/master/images/tetriminos.png "Tetrimino")

*fillit* doesn't consist of recoding Tetris but rather taking in a
file as an argument which contains a list of tetriminos which are 4x4 in size.
Our approach to finding the smallest possible square the pieces could
fit into involves implementing a backtracking algorithm. The backtracking
algorithm traverses the map grid using the first empty '.' that correlates
with a tetrimino grid looking for a free spot. It recurisvely moves the
tetrimino to the right and then down until a free spot is found.
Afterwards the algorithm moves on to the next piece in the input.

The input is passed in as shown below.

input i.e:
![alt text](https://github.com/ug02fast/fillit/blob/master/images/input.png "input")
result i.e:
![alt text](https://github.com/ug02fast/fillit/blob/master/images/result.png "result")

The above result concludes the smallest box grid the tetriminos can fit in
is 6 by 6 in dimensions.
