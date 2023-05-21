#!/bin/bash

sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev && git clone https://github.com/42Paris/minilibx-linux.git && cd minilibx-linux && ./configure
