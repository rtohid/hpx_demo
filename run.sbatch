#!/bin/bash
#SBATCH -p <partition_name>
#SBATCH -N 2
#SBATCH -n 2
#SBATCH -c 2
#SBATCH -J hpx_demo
#SBATCH -o hpx_demo.out
#SBATCH -e hpx_demo.err

module load gcc/15.1.0 boost/1.88.0-release

srun -N 2 -n 2 -c 2 </path/to>/hpx_demo/cmake-build/Release/11_hello_localities

