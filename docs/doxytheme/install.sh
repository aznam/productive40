#!/bin/sh

echo "Installing Mastiware Doxytheme"

dir=`dirname $0`
echo "Moving to $dir"
cd $dir

echo "Copy assets/ to $1/html/"
cp -Rf assets/ $1/html/

echo "Copy search_assets/ to $1/html/search/"
cp -Rf search_assets/ $1/html/search/

echo "End of installation"


