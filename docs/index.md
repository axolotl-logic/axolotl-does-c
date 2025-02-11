# Welcome

Everything you need to get going on a small to medium sized C application with plenty of room to scale.

In order to deliver on client requests quickly without compromising on quality,
I have created templates for common projects.

## Batteries

* Build system generator - CMake
* Static Site Generation for documentation - MkDocs
* Unit Testing - Critereon
* Fuzzing - AFL++

## Bikeshedding

* Cmake source lists are updated manually.

## Project layout

|What|Where|
|---|---|
|Human written documentation|docs/|
|Source code for module|src/${target}/|
|Primary standalone executable (optional)|src/main.c|
|Artifacts generated from program analysis|reports/| 
|CMake Finders|cmake/|
