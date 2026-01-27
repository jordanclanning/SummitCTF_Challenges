🏔️ Summit International CTF – Challenge Walkthroughs

This repository contains complete walkthroughs and source code for a custom Capture-the-Flag (CTF) series focused on reverse engineering, malware analysis, web exploitation, and SOC-relevant security flaws. Challenges are intentionally vulnerable and designed to reflect real-world issues encountered in incident response and defensive security operations.

⚠️ Educational Use Only
All challenges are intentionally insecure and must only be executed in isolated lab environments.

📁 How This Repository Is Organized

Each challenge consists of two components:

📝 Walkthroughs (Authoritative Solutions)

[number].txt files
These are full, step-by-step writeups explaining:

Vulnerability identification

Analysis methodology

Exploitation logic

Flag discovery

Defensive takeaways

Example:

6_EASY_SQLChallenge.txt

💻 Challenge Source Code

All other files (.c, .py, .php, .html, .js, .sql, etc.) are the actual vulnerable challenge implementations used by participants.

Examples:

BufferOverflow.c
MaliciousCalculator.c
EASY_SQLChallenge.php
ClientSide.js
EasyPacketInspection.py

🧩 Challenge Categories
🔐 Validation & Authentication

Code

ValidationSplit.c

ClientSide.html

ClientSide.js

Writeups

2_VALIDATIONSPLIT.txt

3_SplitValidation.txt

Focus:

Split validation logic

Client-side trust failures

Reverse engineering validation routines

🌐 Web Exploitation

Code

HTML_tells_the_truth.html

RemoteCodeExecution.html

XSS_Using_Cookies.php

Writeups

9_HTML_tells_the_truth.txt

Focus:

Hidden logic in HTML/JS

XSS and RCE fundamentals

Input handling flaws

🧵 Reverse Engineering & Memory Exploitation

Code

BufferOverflow.c

SplitMemory.c

SplitMemory.py

MaliciousCalculator.c

Writeups

5_MALICIOUSCALCULATOR.txt

Focus:

Stack overflows

Memory inspection

Runtime flag discovery

GDB + Ghidra workflows

🗃️ SQL Injection

Code

EASY_SQLChallenge.html

EASY_SQLChallenge.php

EASY_SQLChallenge.sql

EASY_SQLChallenge.css

EASY_SQLChallenge.conf

Writeups

6_EASY_SQLChallenge.txt

7_EASY_SQLChallenge.txt

Focus:

Authentication bypass

Query manipulation

Backend logic abuse

📡 Network & Log Analysis

Code

EasyPacketInspection.py

SuspiciousUserAgents.py

Writeups

Included inline in numbered walkthroughs

Focus:

Packet inspection

Log anomaly detection

Behavioral analysis

🧾 Reporting & Documentation

Code

ExecutiveReportAuth.c

Writeups

8_ExecutiveReports2026.txt

Focus:

Translating technical findings into executive-level reporting

Incident documentation discipline

🏁 Flags

All challenges use the standard flag format:

Summit{flag_here}


Flags may be:

Encoded

Split across memory

Generated at runtime

Revealed through exploitation rather than output

🛠️ Recommended Tools

Ghidra

GDB

Wireshark

CyberChef

Burp Suite

SQLMap

Browser Developer Tools

Linux CLI utilities

🧠 Learning Objectives

Participants will gain hands-on experience with:

Reverse engineering C binaries

Web application exploitation

Memory analysis and debugging

Network and log analysis

Writing professional incident and executive reports

🧪 Environment Requirements

Linux VM (Ubuntu or Kali recommended)

Local web server (Apache / PHP)

GCC for C compilation

Isolated lab only — never production

📜 Disclaimer

This repository is provided strictly for educational and defensive security training. Misuse outside of authorized lab environments is prohibited.

👤 Author

Jordan Lanning

# CTF_Challenges
