#!/bin/bash

echo git remote add github.com/transmigracion/movies.git practica1
git remote add github.com/transmigracion/movies.git practica1

echo git add README.md LICENSE push.sh compile.sh *.cpp *.h
git add push.sh compile.sh *.cpp *.h

echo git commit -m $1
git commit -m $1

echo git push practica1 master
git push practica1 master

