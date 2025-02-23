#!/bin/bash
make re && clear && valgrind --leak-check=full --leak-resolution=high --track-fds=yes --trace-children=yes -s --log-file="out.log" ./push_swap