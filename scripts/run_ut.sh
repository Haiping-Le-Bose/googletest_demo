#!/bin/bash

cd build
chmod +x ./CalculatorTest
./CalculatorTest --gtest_output=xml:test_results.xml
python3 ../scripts/xml_converter.py