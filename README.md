Setup and Build Project
=======================

1. Start in C Perspective
2. Build Automatically Off 
3. Download and build Python
  * Download and extract Python-3.4.2
  * Run `./configure`
  * Run `make`
4. File Open Projects for extracted and built Python-3.4.2

Show How To Configure Scanner
=============================

Configuring scanner is often the first issue that people run into on larger projects that were not run in Eclipse. If the scanner is wrong, your code is filled with codan and other errors, making it very difficult to use your project.

1. Show Project Settings: C/C++ General -> Preprocessor Include Paths...
2. Observe Root of project and Include exist under Build Output Parser
3. Show configuration of Build Output Parser
4. Observe how it can be configured per project, file, etc
5. Show GCC Built-ins and how it is picked up.
6. Show ARM Hello project has different settings
7. Show how stdio.h that is opened is different for each project
   - For ARM, open ARM_Hello.c and Ctrl-Click on stdio
   - For Python, open Python.h and Ctrl-Click on stdio
   - Zoom in on tabs to show they are different
8. Same thing is done for symbols
9. Can be done manually, or even provide your own provider

Configure C/C++ Code Analysis
=============================

Codan, short for C/C++ Code Analysis, provides the static analysis of the code. It is highly configurable and additional analysis can be added.

Unfortunately, Codan sometimes has false positives, and sometimes it is not easy to work around such false positives. 

Fortunately Neon now has fine grained (per line) control of Codan. Here is an example:

1. Open ceval.c Goto Line 2570
2. Show how there is a warning about the semi-colon **Point out new feature of expanded ruler**
3. Add ` /* @suppress("Suspicious semicolon") */ ` to make it go away
4. Show how the naming is in Window | Preferences | C/C++ | Code Analysis | Customize Selected
5. Show how the name can be looked up as sometimes the error/warning text is not exactly what is in the @suppress.

Navigate Code
=============

Show various code navigation features:

- Include Browser (Ctrl-3 -> Views: Include Browser, then drag in Python.h)
- C/C++ Index View (caution: Expanding some items can be a little slow on the UI side)
- C/C++ Search, show searching for fileio_write, everything in workspace
- Call Hierarchy, 
  - fileio_write callers with fields on and off
  - fileio_write callees with fields on and off
  - right-click on PyArg_ParseTuple and focus, changing to callers and callees
 - The search and hierarchy are even more valuable in C++ code where simply doing "grep" searches brings up lots of false positives
   - Demo by showing call hierarchy of overloaded in HelloCPP.cpp
 - Macro expansions
  - fileio.c: find Py_XDECREF on line 202
  - Right-click: Explore Macro Expansion
  - Step through the 10 steps of expansion
 - and many more
 
Newest Features
==================

**Parameter Guessing**

- Open `ParameterGuessing.c`
- Show completiongs on `funWith2ATypeObjectParams`, `ov1` and `ov2`.

**
 
Debug
=====

Step Into Selection

- Run to python.c:47 with Run to Line
- Show traditional step into steps into `locale` and then `_PyMem_RawStrdup`
- Restart debug and Run to python.c:47 again
- Then right-click `_PyMem_RawStrdup` and do Step Into Selection

Show Disassembly

- Steps nicely fade the older the instruction gets
- Hover over registers (NEW)

Open Memory Browser

- do `print("Hello ECE")`
- add breakpoint at fileio.c:809
- Show details of `pbuf.buf`, it shows the text value
- Add a tab for `&pbuf` which is a local variable
- Show that the memory view shows all the local variable details (NEW) **Not working with Ubuntu 16.04 system GDB? Use 7.11.1 local built instead**
- Set expression to `$sp` (Stack pointer)
- Show how stack is growing by click on different stack frames

Interact At Console

- do `print("Hello ECE")`
- add breakpoint at fileio.c:809
- do print again
- Show we are stopped
- Scroll in Variables to pbuf->buf, Show it is a void * and not useful as is
- Lets look at it as a string, cast it to char * instead
- Show how it says Hello ECE
- Right-click on it and say Watch so that it can be saved for easy access next time
- Resume and do another print to show
- Now trace it, print the stdout everything that is printed without having to stop
- Add dprintf breakpoint at line 809 instead with this expression:
   `"write: fd=%d len=%d chars=%s", self->fd, len, pbuf.buf`
- do a few simple print
- debug short program to see tracing write to the file

PyDev simultaneous Debug

- Show how "Python-3.4.2 short.py" launch config is using Python-3.4.2 locally built
- Set breakpoints at short.py:1 and :4 (in loop)
- Run it once
- Debug it
- Attach GDB to Python while PyDev is stopped
- Add breakpoint (remove trace) for fileio.c:809
- Press continue and see how we jump back between Python and C

C++ Types

- Debug HelloCPP
- Show how `s1` does not display string, but STL internals
- Create `.gdbinit` with:
```
python
import sys
sys.path.insert(0, '/usr/share/gcc-5/python')
from libstdcxx.v6.printers import register_libstdcxx_printers
register_libstdcxx_printers (None)
end
```
- Debug again, show s1
  