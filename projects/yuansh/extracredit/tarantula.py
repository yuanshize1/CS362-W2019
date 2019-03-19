#!/usr/bin/python

import os
import sys
import subprocess
import random
import math


testsuite = ["unittest1", "unittest2", "unittest3", "unittest4", "cardtest1", "cardtest2", "cardtest3", "cardtest4"]
source_file = 'dominion.c'

 for test in testsuite:
        subprocess.call(['make', 'clean'])
        subprocess.call(['make', test])
        try:
            result = subprocess.check_output(['./' + test], stderr=subprocess.STDOUT)
        except subprocess.CalledProcessError as err:
            result = err.output
