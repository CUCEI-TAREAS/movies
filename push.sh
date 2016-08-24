#!/bin/bash

echo git add push.sh compile.sh *.cpp *.h
git add push.sh compile.sh *.cpp *.h

echo git commit -m $1
git commit -m $1

echo git push practica1 master
git push practica1 master

