1. pre-processor directives
2. code distributed across .cpp files 

### namespaces

They provide the opportunity to separate names into different spaces such that different objects can carry the same name. Confusion between the objects is avoided by encapsulating each of them in their own namespace. All methods belonging to a particular class can for example be separated from equally named methods from a different class. Think of `get_name()` or `set_name()` type methods.
I believe namespaces are not restricted to classes, however. Any encapsulation (for libraries or else) like

```
namespace my_space {
	void a_function(int a) {return 1 + a;};
	int a = 0;
}
```

will do. Does it need a final semi-colon?
Access is provided via the double-colon operator 

```
my_space::a_function(my_space::a); // 1
```


### start of programme

The beginning of any programme starts with a procedure called `main()`. E.g.

```
ìnt main() {return 0;};
```

When the programme is exectuted by a user, this is where things will start off. I believe compiling code that does not have a `main()` procedure will fail (give it a try?). Where would the programme start when executed?

### Some terminology

Some programming lingo.

##### object



##### variable
##### type

##### procedure



##### function

This terminology is not standard. I will refer to special kinds of procedures as functions. Those procedures that map inputs to outputs bijectively(?) will be called functions, as in the mathematical sense. This requires, in particular, that a procedure does not have side-effects and that it does not depend on any other state besides its arguments. A procedure operating on a pointer or a reference or a method of a OOP-style object will typically not be a function in the mathematical sense.

##### function definition
##### function call
##### command
##### return type

In C++, every procedure will return either nothing, in which case the return type is `void` or an object with a specific type that needs to be declared when the procedure is defined. In this sense, C++ is a strongly-typed language (?). 
Maybe, the necessity for declaring a specific type can be reduced using `auto`. However, I am not really sure about this. In any case, it makes code harder to reason about.
Can a procedure return another procedure? Are there "first-class" functions in C++?

##### declaration

Allocating memory for an object and declaring object's name.

```
int a;
```

##### assignment

Assigning a specific value to an object; manipulating memory to hold a particular value.

```
a = 0;
```

##### initialisation

Combining declaration and assignment into one step.

```
int a = 0;
```

##### instantiation

Initialisation of an object of a class.

##### encapsulation

The process of placing functionality in a specific class and limiting access from outside to a minimum.

##### directive
##### flow control

Control the flow of execution by instating conditionals such as `if`, `ìfelse`, and `else` statements, repeat commands while varying certain parameters using `for`, `while` and `do while` loops, or use `switch`es to condition on a limited, discrete set of values a variable can take.
Note: syntax for ifelse, do() while(), and switch().

##### compile-time

Point in time when code is being compiled/translated into an executable, binary file.

##### run-time

Point in time when binary file is executed.

##### programme

6. operators, logical operators, prefix notation, postfix notation
7. function: definition, call, body, return type
8. arrays, pointers, references, pointer arithmetic
9. classes: namespace, constructor/destructor, header files, member variables / attributes, methods, private, public, 
10. const, static
11. scope
12. compiler
13. standard