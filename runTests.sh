#!/bin/bash

$1
retval=$?
echo "Test returned: $retval"
pwd
xsltproc --nodtdattr -o libmudirmsghandlerdrvTest-Results.html CUnit-Run.xsl libmudirmsghandlerdrvTest-Results.xml
xsltproc --nodtdattr -o libmudirmsghandlerdrvTest-Listing.html CUnit-List.xsl libmudirmsghandlerdrvTest-Listing.xml
mv testoutput/obj1/*.gc* src
gcov src/* -m

if [ $retval -ne 0 ]
then
  touch ./unittestfail
fi
