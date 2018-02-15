pkg-dot
=======

Reads the output of FreeBSD's pkg info -d from standard input and writes
dia(1) markup to standard output.

Examples
--------

Graph all of Firefox' dependencies:

    pkg info -d firefox | pkg-dot | dot -Tpng >out.png

Or, of all installed packages:

    pkg info -aq | xargs pkg info -d | pkg-dot | dot -Tpng >out.png

Building
--------

    make

Authors
-------

Sijmen J. Mulder <ik@sjmulder.nl>.
