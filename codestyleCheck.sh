#!/bin/sh

try() {
    "$@"
    status=$?
    if [ $status -ne 0 ]; then
        echo "ERROR with '$@' in $dir"
        exit $status
    fi
    return $status
}

Header() {
    echo ""
    echo "*****************************************************"
    echo "$@"
    echo "*****************************************************"
    echo ""
}

CheckGoogleStyleInDir() {
    retCode=0

    echo "Checking $dir"
    sources=`find . -name "*.hpp" -or -name "*.h" -or -name "*.cpp" -or -name "*.cxx"`
    for file in $sources;
    do
        python "../cpplint.py" $file
        status=$?
        if [ $status -ne 0 ]; then
            retCode=$status
        fi
    done

    return $retCode
}

CheckGoogleStyle() {
    Header "Check \"Google C++ Style\""

    for dir in */;
    do
        cd $dir
        try CheckGoogleStyleInDir
        cd ..
        echo ""
    done
}

Main() {
    CheckGoogleStyle
}

Main

