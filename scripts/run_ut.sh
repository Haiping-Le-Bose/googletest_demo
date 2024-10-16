mkdir build
cd build
cmake ../
make
./CalculatorTest --gtest_output=xml:test-results.xml