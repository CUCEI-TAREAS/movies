#!/bin/bash
echo git remote add practica1 https://github.com/transmigracion/movies.git
git remote add practica1 https://github.com/transmigracion/movies.git

echo git add README.md LICENSE push.sh compile.sh *.cpp *.h
git add push.sh compile.sh *.cpp *.h

echo git commit -m $1
git commit -m $1

echo git push practica1 master
git push practica1 master

