# ☕ Kenyan Coffee Export Workflow Management System

A C programming project that simulates the workflow of processing Kenyan coffee for export. The program guides users through every stage of the export process, from receiving raw coffee to approving or rejecting batches for shipment. It also generates an audit log (`results.txt`) containing all processing details.

---

## 📌 Project Information

**Course:** STU 1201 – Introduction to Programming

**Group 4 Members**
- Nyabaro Chris Kinaro – 25/10415
- Bercyn Onyango – 23/05477
- Mathew Kariuki – 25/06603
- Bethwel Cheruiyot – 25/08011

---

## ✨ Features

- Process multiple coffee batches
- Record supplier details and received weight
- Perform basic quality inspection
- Check power availability (KPLC or Generator)
- Select Wet Mill or Dry Mill processing
- Evaluate coffee grade and defect count
- Record packaging information
- Verify export certificates
- Approve or hold export shipments
- Generate a complete audit log (`results.txt`)

---

## 📋 Workflow

1. Raw Material Reception
2. Basic Inspection
3. Electricity Check
4. Processing Preparation
5. Quality Check
6. Packaging
7. Export Decision

---

## 📁 Project Files

```
Coffee Export Workflow
│── COFFEE EXPORT WORKFLOW 2.c   # Source code
│── results.txt                  # Generated audit log
│── README.md                    # Project documentation
```

---

## ⚙️ Requirements

- GCC Compiler (MinGW, GCC, or Dev-C++)
- Windows, Linux, or macOS

---

## ▶️ How to Compile

Using GCC:

```bash
gcc "COFFEE EXPORT WORKFLOW 2.c" -o coffee_export
```

Run the program:

```bash
./coffee_export
```

On Windows:

```bash
coffee_export.exe
```

---

## 📄 Output

After processing all batches, the program creates a **results.txt** file containing:

- Supplier information
- Batch weight
- Inspection results
- Power source used
- Processing method
- Coffee grade
- Packaging details
- Export approval status

This file serves as an audit trail for every processed batch.

---

## 🎯 Learning Objectives

This project demonstrates:

- C programming fundamentals
- Variables and data types
- User input/output
- Conditional statements
- Loops
- Functions
- File handling
- Workflow simulation
- Real-world business process automation

---

## 📜 License

This project was developed for educational purposes as part of the **STU 1201 – Introduction to Programming** course.
