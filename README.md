# CS 3251: Intermediate Software Design
## Programming Assignment 4


This assignment focuses on strong exception safety and linked-lists. While similar to Assignment 3, this assignment has you implementing a more complex data structure.  The linked list uses linked nodes to create the list. This linked list is a circular doubly-linked list and uses a dummy node. You need to be certain that you read and understand all comments in the files.

You are provided with several files.  DO NOT CHANGE THESE FILES:
* _include/AllocationTracker.h_ and _src/AllocationTracker.cpp_
* _include/LinkedList.h_
* _include/LinkedListNode.h_
* _include/LinkedListIterators.h_

You are also provided with several files for use in testing your implementation.  DO NOT CHANGE THESE FILES:
* _tests/main.cpp_
* _tests/linkedListTest.cpp_
* _tests/constLinkedListTest.cpp_
* _CMakeLists.txt_

### All Students Must:

* Create the file _LinkedList.cpp_ that contains the strongly exception safe implementations outlined in _LinkedList.h_. You need to test your code with _linkedListTest.cpp_.
* Create the file _LinkedListNode.cpp_ that contains the strongly exception safe implementations outlined in _LinkedListNode.h_. You need to test your code with _linkedListTest.cpp_.
* Create the file _LinkedListIterators.cpp_ that implements iterators (both regular and const) for the linked list container. You need to test your code with _tests/linkedListTest.cpp_.

### Graduate Students Must:

* Implement six unit tests as outlined in _tests/constLinkedListTest.cpp_.  These tests should exercise functionality specific to the const LinkedList iterator.


## WARNING: DO NOT WAIT TO START THIS ASSIGNMENT! IT WILL LIKELY TAKE MORE TIME THAN THE LAST ASSIGNMENT!

All students are required to use the CS 3251 coding standard, available on the [course webpage](https://vuse-cs3251.github.io). Points will be deducted for not following the standard.

The assignment is to be submitted using the link to github.com sent out via email to all class members. DO NOT email your assignment to the professor or the TAs.  Emailed assignments ARE NOT accepted.  We will grade the last commit to your repository before the deadline date and time.  Any commits after that moment will be ignored.  If nothing has been committed at that time you will receive a zero grade. 


### REMINDERS:

* Ensure that your name, vunetid, email address, and the honor code appear in the header comments of all files that you have altered.

* Do not alter any of the project files unless explicitly directed otherwise!  Work only on those files specified above.  You must use the supplied `CMakeLists.txt` file as is.

* All students are required to abide by the CS 3251 coding standard, available on the course web page and provided to you on the first day of class. Points will be deducted for not following the coding standard.

* For full credit, your program must compile with a recent version of `clang` and run successfully with Travis CI.
  * Your code will be treated as if it failed to compile if you do not turn Travis builds on.
  * You will have to turn on Travis builds for your repository and then push to trigger a Travis build.
  * The Travis build *will* fail if your code is not properly formatted. **This is by design.** If your code is compiling and running successfully, but the build is failing, then your build is most likely failing because your code is not passing the linter. This can be confirmed by checking if a command involving `clang-format` in the Travis build output log has an exit code of 1.

* Your program(s) should always have an exit code of 0.  A non-zero exit code (generally indicative of a segmentation fault or some other system error) is reason to worry and must be corrected for full points.
  
* When submitting the assignment, all files that are provided to you, plus your solution files have been submitted. All files necessary to compile and run your program must reside in the GitHub.com repository.

