#!/usr/bin/python3
#
# Extract course data from a degree audit saved as HTML
# - usage: ./reduce.py filename
#
# spaces in course prefixes and numbers are replaced with
# hyphens for easy C++ input processing
#

import os
import sys
# re is the regexp package
import re
import codecs

termRegEx = re.compile('^.*class=\"term\"[^>]*>([^<]*)<.*$')
courseRegEx = re.compile('^.*class=\"course\"[^>]*>([^0-9]*)([^<]*)<.*$')
creditRegEx = re.compile('^.*class=\"credit\"[^>]*>([^<]*)<.*$')
gradeRegEx = re.compile('^.*class=\"grade\"[^>]*>([^<]*)<.*$')
subreqRegEx = re.compile('^.*class=\"subreqTitle\"[^>]*>([^<]*)<.*$')
endingRegEx = re.compile('^.*GE-LEGEND.*$')

# the saved HTML file has some non-ASCII characters in it,
# so we need to have a file reader that will ignore these 
fileIn = codecs.open(sys.argv[1], 'r', encoding='utf-8', errors='ignore')

for line in fileIn:
   line = line.strip()
   if line is None:
      break
   match = endingRegEx.fullmatch(line)
   if match is not None:
      break
   match = subreqRegEx.fullmatch(line)
   if match is not None:
      subreq = match.groups()[0].strip()
      #print(subreq)
   match = termRegEx.fullmatch(line)
   if match is not None:
      term = match.groups()[0].strip()
      #print('term:',term)
   match = courseRegEx.fullmatch(line)
   if match is not None:
      coursePrefix = match.groups()[0].strip().replace(' ','-')
      courseNumber = match.groups()[1].strip().replace(' ','-')
      #print('course:',course)
   match = creditRegEx.fullmatch(line)
   if match is not None:
      credit = match.groups()[0].strip()
      #print('credit:',credit)
   match = gradeRegEx.fullmatch(line)
   if match is not None:
      grade = match.groups()[0].strip()
      print('{0} {1} {2} {3} {4}'.format(term, coursePrefix,
            courseNumber, credit, grade))

exit(0)

