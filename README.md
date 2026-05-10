
  AASTU Employee Information System 

A robust C++ console application designed to manage and retrieve staff records efficiently. This project demonstrates core concepts of Object-Oriented Programming (OOP), data structures (Vectors), and search algorithms.

   Features
- Staff Recording: Add new employee profiles with unique IDs and details.
- Record Display: View a formatted list of all staff members currently in the system.
- Smart Search: Search for employees using:
  - ID Match: Exact, case-sensitive identification.
  - Name Match: Case-insensitive search for better user experience.
- Data Integrity: Includes input buffer clearing to prevent menu skipping errors.

  Technical Skills Demonstrated
- Language: C++
- Data Management: Use of std::vector for dynamic memory management.
- Logic: Implementation of do-while loops, switch-case menus, and const auto& for efficient memory usage during iteration.
- String Manipulation: Custom case-insensitive string comparison logic.

How to Compile and Run
1. Ensure you have a C++ compiler installed (like `g++`).
2. Save the code as main.cpp.
3. Open your terminal/command prompt and run:
   ```bash
   g++ main.cpp -o EmployeeSystem
   ./EmployeeSystem
