#!/bin/bash

problem=walk

set -e
rm -f "${problem}.jar" *.class
javac "grader.java" "${problem}.java" -Xlint:all
jar cfe "${problem}.jar" "grader" *.class
