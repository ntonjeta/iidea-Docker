# bellerophon-docker
Docker image for Iidea

### Introduction to Bellerophont ###
------------

Bellerophont is a genetic optimization tools, used in approximate computing context.
It is developed to use in collaboration with [clang-Chimera] (https://github.com/ntonjeta/clang-chimera). clang-Chimera provide code mutation, and Bellerophon use genetic algorithm to find the pareto-front of possible approximation. 

More details of Bellerophon implementation can found on my master's thesis.

#### Example ####
-------- 

You can test a simple exampe provide in the image: 

    docker run -it ...

The example use bit lenght reduction approximate technique, provided by [FLAP library] (https://github.com/Ghost047/Fap). 

### LICENSE ###
--------

* [GPLV3.0](https://www.gnu.org/licenses/licenses.html)

### Contributing ###
----------

Github is for social coding: if you want to write code, I encourage contributions through pull requests from forks of this repository. 
