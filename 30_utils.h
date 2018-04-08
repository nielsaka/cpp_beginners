

// could be anything
// but by convention use FILENAME_H_
#ifndef UTILS_H_ // if not defined, do:
#define UTILS_H_ // define 

void do_something();

#endif // end of if clause

// preprocessor might process this file several times, having spread
// inclusion of header file across several files
// after the first time, UTILS_H_ will have been defined
// no need to run again

// modularity, DRY