#!/bin/bash

module load gcc/15.1.0 boost/1.88.0-release

CURRENT_DIR=$1
PREFIX="${CURRENT_DIR:=$(pwd)}"

BUILD_TYPE=Release

HPX_HOME=${PREFIX}/hpx/cmake-install/${BUILD_TYPE}/lib64/cmake/HPX
BUILD_DIR=${PREFIX}/cmake-build/${BUILD_TYPE}
INSTALL_DIR=${PREFIX}/cmake-install/${BUILD_TYPE}

echo $HPX_HOME
cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE}               \
      -DHPX_DIR=${HPX_HOME}                          \
      -S ${PREFIX} -B ${BUILD_DIR}

cmake --build ${BUILD_DIR} --parallel 
cmake --install ${BUILD_DIR} --prefix ${INSTALL_DIR}
