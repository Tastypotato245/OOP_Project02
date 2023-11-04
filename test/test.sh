#!/bin/bash

while read line
do
    ${1} $line
done < ${2}
