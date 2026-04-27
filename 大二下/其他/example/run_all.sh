#!/bin/bash

mkdir -p results
mkdir -p bin

for cpp in *_main.cpp
do
    id="${cpp%_main.cpp}"
    echo "Compiling $cpp ..."

    g++ -std=c++17 -O2 "$cpp" -o "bin/$id"

    if [ $? -ne 0 ]; then
        echo "Compile failed: $cpp"
        continue
    fi

    mkdir -p "results/$id"

    for test in tests/*.txt
    do
        case_name=$(basename "$test" .txt)
        echo "Running $id on $case_name ..."

        "./bin/$id" "results/$id/${case_name}.svg" < "$test" \
            > "results/$id/${case_name}.out" \
            2> "results/$id/${case_name}.err"
    done
done

echo "Done."
