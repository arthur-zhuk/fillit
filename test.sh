echo **Normal
./a.out test_inputs/bit_tetriminos
echo **Double New Line
./a.out test_inputs/doublenewline
echo **Input file with bs in it
./a.out test_inputs/invalidfile
echo **Weird piece using acceptable chars
./a.out test_inputs/invalidpiece
echo **Not enough chars in piece
./a.out test_inputs/notenough_chars
echo **Small Piece with appropriate chars but not 4 in len
./a.out test_inputs/smallpiece
echo **New line in strange place to break new line checker
./a.out test_inputs/strangeplacenewline
echo **When there is a symbol other than pound or period
./a.out test_inputs/symbolotherthan
