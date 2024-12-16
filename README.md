# SGTC-assignment-01

## Problem Statement

***Compose a C++ solution for the following problem statement and execute the testing procedures on that solution. Adhere to the coding guidelines outlined by Stryker.***

Develop a **patient record management system solution** capable of adding, deleting, and updating patient data, with the following details. Users should be able to execute the listed operations on patient data. Smart pointers are recommended for memory management.

Patient Data:

- Name: String
- Date of Birth (DOB): Date
- Surgery Date: Date
- Surgeon Name: String
- Joint Name: Enum (Hip, Shoulder, Knee)
- Operative Side: Enum (Left, Right)

Operations:

- Add a new patient
- Display patient details
- Search by name
- Search by surgeon name
- Search by joint name
- Search by operative side
- Sort by any field
- Filter by any field

Testing:

- Add atleast 10 dummy patient data.
- Execute at least 4 operations (from the above list) on the dummy patient data.

link to problem statement: https://stryker-agile.atlassian.net/wiki/spaces/CS/pages/2944991323/C+Assignment+2+Patient+records+management

## Build Instructions

- usual cmake build sequence.
- go to base of the project tree.

```bash
mkdir build
cd build
cmake ..
make
./assignment
```

## Screenshots

[TODO] update this

## Contributions welcome

Feel free to asign MRs to me over this repository. Contributions are welcome!
