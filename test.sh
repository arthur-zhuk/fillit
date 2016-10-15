echo **Normal
./a.out test_inputs/test_valid1

echo **Double New Line
./a.out test_inputs/test_dblnline

echo **Input file with bs in it
./a.out test_inputs/test_invldfile

echo **Weird piece using acceptable chars
./a.out test_inputs/test_invldpce

echo **Not enough chars in piece
./a.out test_inputs/test_misingchars

echo **Small Piece with appropriate chars but less than 4 in len
./a.out test_inputs/test_smlpiece

echo **Big Piece with Appropriate Chars but 5 in Len
./a.out test_inputs/test_bigpiece

echo **New line in strange place to break new line checker
./a.out test_inputs/test_nlrndomplace

echo **When there is a symbol other than pound or period
./a.out test_inputs/test_diffsymb

echo **Kanes OL test
./a.out test_inputs/test_OL

echo **Just a square to make sure condition logic doesnt overlook smaller numbers
./a.out test_inputs/test_square
