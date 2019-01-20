#!/bin/bash

mkdir -p ~/.local/bin/
ln -sf $PWD/sketch      ~/.local/bin/sketch
ln -sf $PWD/algo-run    ~/.local/bin/algo-run
ln -sf $PWD/algo-make   ~/.local/bin/algo-make
ln -sf $PWD/algo-split  ~/.local/bin/algo-split

cd third_party/ByteHelper
npm install
npm start

