#!/bin/bash
message = $1
git add push.sh compile.sh *.cpp *.h
git commit -m message
git push practica1 master
