
echo **Double New Line
./fillit test_inputs/test_dblnline

echo **Input file with bs in it
./fillit test_inputs/test_invldfile

echo **Weird piece using acceptable chars
./fillit test_inputs/test_invldpce

echo **Invalid piece 2
./fillit test_inputs/test_invalid_piece_2

echo **Invalid piece 3
./fillit test_inputs/test_invalid_piece_3

echo **Not enough chars in piece
./fillit test_inputs/test_misingchars

echo **Small Piece with appropriate chars but less than 4 in len
./fillit test_inputs/test_smlpiece

echo **Big Piece with Appropriate Chars but 5 in Len
./fillit test_inputs/test_bigpiece

echo **New line in strange place to break new line checker
./fillit test_inputs/test_nlrndomplace

echo **Double nl at end
./fillit test_inputs/test_nl2

echo **New line in middle
./fillit test_inputs/test_nl1

echo **When there is a symbol other than pound or period
./fillit test_inputs/test_diffsymb

echo **Space at end
./fillit test_inputs/test_space_at_end

echo **Normal
./fillit test_inputs/test_valid1

echo **Kanes OL test
./fillit test_inputs/test_OL

echo **Just a square to make sure condition logic doesnt overlook smaller numbers
./fillit test_inputs/test_square

echo **Same pieces smaller
./fillit test_inputs/test_same_pieces_small

echo **Subject Example 1
./fillit test_inputs/test_subject_example_1

echo **Subject Example 2
./fillit test_inputs/test_subject_example_2

