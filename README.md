# fillit
The goal of this project is to arrange the Tetriminos among themselves to make the smallest possible square.

Fast start: 

<pre>
<code>
git clone https://github.com/timchuchok/fillit.git
cd fillit
make && make clean
./fillit maps/one_of_maps
</code>
</pre>


<H1>More Details</H1>
<p>Executable must take as parameter one (and only one) file which contains a
list of Tetriminos to arrange. This file has a very specific format : every Tetriminos
description consists of 4 lines and each Tetriminos are separated by an empty line

The description of a Tetriminos must respect the following rules :

• Precisely 4 lines of 4 characters followed by a new line.

• A Tetriminos is a classic piece of Tetris composed of 4 blocks.

• Each character must be either a ’#’ when the character is one of the 4 blocks of
a Tetriminos or a ’.’ if it’s empty.

• Each block of a Tetriminos must be in contact with at least one other block on
any of his 4 sides.

A few examples of valid descriptions of Tetriminos :
