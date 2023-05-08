build() {
    /usr/bin/cmake --no-warn-unused-cli \
        -DCMAKE_BUILD_TYPE:STRING=Debug \
        -S$(pwd) \
        -B$(pwd)/build \
        -G "Unix Makefiles"
}

clean() {
    rm -rf ./build/*
}

run() {
    cmake --build build
    ./build/sandbox
}

av_args=(run build clean)

if [ ! -d "build" ]; then
    mkdir build
fi

for arg in "$@"; do
    if echo ${av_args[@]} | grep -q -w $arg; then
        $arg
    else
        echo -e "COMMAND NOT FOUND: $arg";
        echo -e "Available commands: \n\t- $(echo ${av_args[@]} | sed -e 's/ /\n\t\- /g')"
    fi
done

