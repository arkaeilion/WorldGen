#!/bin/sh/
MSBuild.exe build/WouldGen/WouldGen.vcxproj
rm -r build/WouldGen/Debug/Resources/*
cp -R WouldGen/Resources build/WouldGen/Debug/
