# OOP Design Considerations
 
## Design Approach

1. up-front design tends to be less productive
2. deciding as you go allows to review decisions and alter design more easily

The last point can take the form of building a prototype and then iterate continuously on it. I am sure this has some fancy name in software engineering? 
Before deciding on a particular class structure, it might be a good idea to start writing out code and then move to classes in a second stage to get a feeling for what makes sense.

## OOP Design Decisions

What are sensible classes? Which parts can be separated? Is it a matter of taste, is there an overall optimum or does it depend on specific objectives like code performance, productivity, correctness, collaboration?

Where to delineate encapsulation? How to decide on what belongs to which module?

Guiding principles:

* **re-usable**: can this class be re-used in another programme? can code duplication be reduced in the current programme? do not repeat (DRY).
* **self-contained**: can readers easily reason about the logic behind the code: what its purpose is, how individual components interact and when or in what sequence it will be executed?
* **independent**: could internal or external dependencies further be restricted? This includes calls to any kind of interface such as specific libraries, APIs, or classes? Which (local) classes need to know about each other?

There is definitely some overlap between these principles, but they do not necessarily coincide. For example, minimum dependence supports re-use and self-containment of the code, but also safeguards against disruptions due to changes in any of these dependencies and makes code more modular such that individual components can be more easily replaced. 

While these guiding principles provide great generality, for specific design decisions, ask yourself

* which parts could be re-used in another application?
* which parts are already duplicated in the current application?

* which commands can be grouped such that they represent an autonomous process serving a particular purpose?
* what is endogenous (changed) and what is exogenous (given) in that process?
* where do these processes need to interface? can I keep implementation details hidden and just surface the purpose? The endogenous and exogenous divide might help here.
* do similar purposes exist, that are reformulations or variations of the current purpose?

-> put code in methods and attributes of class; decide on private/public.