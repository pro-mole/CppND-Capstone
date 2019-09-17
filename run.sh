#!/bin/bash

if [ -f ./RogueLite ]
then
    ./RogueLite
else
    ./make.sh && ./RogueLite
fi
