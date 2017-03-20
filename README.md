# Iidea-docker
<!--[![Build Status](https://travis-ci.org/ntonjeta/iidea-Docker.svg?branch=master)](https://travis-ci.org/ntonjeta/iidea-Docker)-->
[![](https://images.microbadger.com/badges/image/ntonjet/iidea-docker.svg)](https://microbadger.com/images/ntonjet/iidea-docker "Get your own image badge on microbadger.com")
------------

ArchLinux-base Docker image with Iidea tool

### Introduction to Bellerophon ###
------------

Bellerophont is a genetic optimization tools, used in approximate computing context. It is developed to use in collaboration with [clang-Chimera] (https://github.com/ntonjeta/clang-chimera). Clang-Chimera provide code mutation, and Bellerophon use genetic algorithm to find the pareto-front of possible approximation. 

You can find more details about Bellerophon at [ntonjeta/bellerophon] (https://github.com/ntonjeta/Bellerophon).

### How use container ###

1) Download and build container 
    
    - git clone https://github.com/ntonjeta/iidea-Docker
    - cd iidea-Docker/
    - docker build -t <name> . 

It will take some minutes for download and build neccesary.

2) Run container and mount volume
  
    - docker run -dit -v /path/to/host/folder:/absolute/path/to/container/folder/ <container hash> 

3) Attach to container 

    - docker attach <containerhash> 

Now you have an interactive shell in wich you can use "clang-chimnera" and "bellerophon" tool. Furthermore, you can use volume for share file with host machine. 

#### Example ####
-------- 

You can test a simple example: 

    docker run -it ...

The example use bit lenght reduction approximate technique, provided by [FLAP library] (https://github.com/Ghost047/Fap). 

### LICENSE ###
--------

* [GPLV3.0](https://www.gnu.org/licenses/licenses.html)

### Contributing ###
----------

Github is for social coding: if you want to write code, I encourage contributions through pull requests from forks of this repository. 
