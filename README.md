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
  Executable must take as parameter one (and only one) file which contains a
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

<pre>
<code>
....  ....  ####  ....  .##.  ....  .#..  ....  ....
..##  ....  ....  ....  ..##  .##.  ###.  ##..  .##.
..#.  ..##  ....  ##..  ....  ##..  ....  #...  ..#.
..#.  ..##  ....  ##..  ....  ....  ....  #...  ..#.
</code>
</pre>

A few examples of invalid descriptions of Tetriminos

<pre>
<code>
####  ...#  ##...  #.  ....  ..##  ####  ,,,,  .HH.
...#  ..#.  ##...  ##  ....  ....  ####  ####  HH..
....  .#..  ....   #.  ....  ....  ####  ,,,,  ....
....  #...  ....       ....  ##..  ####  ,,,,  ....
</code>
</pre>

<h2>The smallest square</h2>

The goal of this project is to arrange the Tetriminos among themselves to make the
smallest possible square, but in some cases, this square may have holes when some given
pieces won’t fit perfectly with others.

Each Tetrimino, even if presented on a 16 box grid, is only defined by its full boxes (his
’#’). The 12 remaining Tetriminos will be ignored for the arrangement of Tetriminos
among themselves.

  The Tetriminos are ordered as they appear in the file. Among the different solutions
possible to make the smallest square, only the solution where Tetriminos is placed on
their most upper-left position, will be accepted/retained.

Example :
  If we consider the two following Tetriminos (the ’#’ are replaced by digits for understanding
purposes) :

<pre>
1...      ....
1...      ....
1... AND  ..22
1...      ..22
</pre>
The smallest square formed by those 2 pieces is 4 boxes wide, but there is many
versions that you can see right below :
<pre>
a)   b)   c)   d)   e)   f)
122. 1.22 1... 1... 1... 1...
122. 1.22 122. 1.22 1... 1...
1... 1... 122. 1.22 122. 1.22
1... 1... 1... 1... 122. 1.22
g)   h)   i)   j)   k)   l)
.122 .1.. .1.. 221. ..1. ..1.
.122 .122 .1.. 221. 221. ..1.
.1.. .122 .122 ..1. 221. 221.
.1.. .1.. .122 ..1. ..1. 221.
m)   n)   o)   p)   q)   r)
22.1 .221 ...1 ...1 ...1 ...1
22.1 .221 22.1 .221 ...1 ...1
...1 ...1 22.1 .221 22.1 .221
...1 ...1 ...1 ...1 22.1 .221
</pre>
According to the rule above, the right solution is then a)

<h2>Program output</h2>

Program display the smallest square solution on the standard output. To
identify each Tetriminos in the square solution, it will assign a capital letter (starting
with ’A’) to each Tetriminos in the order they appear in the file. A file will contain 26
Tetriminos maximum.

If the file contains at least one error, program display error on the standard
output and will exit.

Example :
<pre>
$> cat sample.fillit | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$
$> ./fillit sample.fillit | cat -e
DDAA$
CDDA$
CCCA$
BBBB$
$>
</pre>

Another example :
<pre>
$> cat sample.fillit | cat -e
....$
....$
####$
....$
$
....$
...$
..##$
..##$
$> ./fillit sample.fillit | cat -e
error$
$>
</pre>
