#!/bin/bash

module load gcc/15.1.0 boost/1.88.0-release

CURRENT_DIR=$1
PREFIX="${CURRENT_DIR:=$(pwd)}"

BUILD_TYPE=Release
HPX_DIR=${PREFIX}/hpx
BUILD_DIR=${HPX_DIR}/cmake-build/${BUILD_TYPE}
INSTALL_DIR=${HPX_DIR}/cmake-install/${BUILD_TYPE}


mkdir -p ${PREFIX}

if [ ! -d "${HPX_DIR}" ]; then
  git clone git@github.com:STEllAR-GROUP/hpx.git ${HPX_DIR}
fi

cd ${HPX_DIR}
cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE}               \
      -DCMAKE_CXX_FLAGS="-std=c++17"                 \
      -DCMAKE_CXX_COMPILER=g++                       \
      -DHPX_WITH_THREAD_IDLE_RATES=ON                \
      -DHPX_WITH_MALLOC=tcmalloc                     \
      -DHPX_WITH_EXAMPLES=OFF                        \
      -DHPX_WITH_FETCH_APEX=ON                       \
      -DHPX_WITH_FETCH_ASIO=ON                       \
      -DCMAKE_EXPORT_COMPILE_COMMANDS=ON             \
      -Wdev -S ${HPX_DIR} -B ${BUILD_DIR}

cmake --build ${BUILD_DIR}/ --parallel 
cmake --install ${BUILD_DIR}/ --prefix ${INSTALL_DIR}

