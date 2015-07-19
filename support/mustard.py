#!/usr/bin/env python
# -*- encoding: utf-8 -*-
import os
import subprocess
import sys

BASE_PATH = os.path.dirname(os.path.realpath(sys.argv[0]))
BASE_PATH = os.path.dirname(BASE_PATH)

if len(sys.argv) < 3:
    print 'usage: python mustard.py <CMD> <MODULE>'
    print '\t CMD - crun | run'
    exit()

cmd = sys.argv[1]
module = sys.argv[2]

cmd_supports = set(['crun', 'run'])
if cmd not in cmd_supports:
    print 'unknown CMD: ' + cmd
    exit()

if cmd == 'crun':
    command = 'g++ -o {0}.out -I. -I{1} {0}.cpp {0}.test.cpp'.format(module, BASE_PATH)
    code = os.system(command)
    if code != 0:
        exit()

# cmd == 'run'
input_file_path = module + '.input'
lines = []
with open(input_file_path) as fin:
    lines = fin.readlines()
lines.append('\n')

exe_file = './' + module + '.out'
inputs = []
counter = 1
for i in xrange(0, len(lines)):
    if len(lines[i].strip()) == 0:
        print '\n===== [' + str(counter) + '] ====='
        counter += 1
        if len(inputs) == 0:
            continue
        p = subprocess.Popen(exe_file, stdin=subprocess.PIPE)
        for line in inputs:
            print line.strip()
            p.stdin.write(line)
        p.stdin.close()
        p.wait()
        inputs = []
    else:
         inputs.append(lines[i])

