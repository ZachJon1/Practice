mkdir -p install/include
mkdir -p install/lib

cp -r include/* install/include

cp results/lib/*.a install/lib

cp -r build/* install/

