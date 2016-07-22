#!/usr/bin/env bash

svn2git https://svn.code.sf.net/p/emplan/code/ --trunk trunk/EmPlan  --notags --nobranches --username meneguzzi --authors authors.txt -v
