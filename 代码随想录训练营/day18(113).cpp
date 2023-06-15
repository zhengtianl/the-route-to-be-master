#!/bin/bash
#SBATCH --partition = physical
#SBATCH --job-name=your_job_name
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=4
#SBATCH --time=01:00:00
#SBATCH --output=output_file.out

module load python3.8 MPI


