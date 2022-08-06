#!/bin/bash

find . -name "*.sh" | ls | sed -n 's/\.sh$//p'