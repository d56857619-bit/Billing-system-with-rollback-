 Billing System (C++)
Overview
This project is a lightweight Billing System Reader implemented in C++ with support for:
- File-based data persistence
- Transaction handling (Begin, Commit, Rollback)
- Safe data manipulation using temporary buffers

The system mimics basic ACID transaction principles without requiring a full database.

 Features
- Load billing records from file
- Add and modify billing entries
-  Rollback changes before saving
-  Save (commit) changes to file
-  In-memory transaction buffer for safety

System Design
The system uses two main data structures:
- Main Data (Persistent State)
  Stores the actual billing records loaded from file.
- Transaction Buffer (Temporary State)
  Stores changes made during a session before committing.

Workflow
1. Load data from file
2. Start transaction (implicit)
3. Make changes (add/edit/delete)
4. Choose:
   - Commit → Save changes to file
   - Rollback → Discard changes


📁 File Structure
/billing-system
│── main.cpp
│── BillingSystem.h
│── BillingSystem.cpp
│── billing.txt
│── README.md


Requirements
- C++ compiler (G++ recommended)
- C++11 or later


 Compilation & Run
g++ main.cpp BillingSystem.cpp -o billing
./billing

Data Format
The system stores records in a simple text format:

Name,Amount
Electricity,500
Water,300
Internet,200



Example Usage
1. View Bills
2. Add Bill
3. Save Changes
4. Rollback
5. Exit

Sample Flow
- Add a bill → stored in buffer
- Choose Save → written to file
- Choose Rollback → changes discarded


 Transaction Methods
Method| Description
Begin| Starts a new transaction (implicit)
Commit| Saves buffer to file
Rollback| Restores original data


 Data Safety
- Original file is never modified until commit
- Rollback ensures recovery from unwanted changes
- Prevents accidental data corruption


 Limitations
- Single-user system
- No concurrency control
- No encryption or authentication
- Uses basic file storage (not optimized for large datasets)


 Future Improvements
- GUI interface (Qt / web-based)
- Database integration (SQLite/MySQL)
- Multi-user support with locking
- Input validation & error handling
- Logging system for transactions

 Author
Desiree


License
This project is open-source and free to use for educational purposes.

