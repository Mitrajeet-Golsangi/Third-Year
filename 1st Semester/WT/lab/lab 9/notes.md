# Spring Boot <!-- omit in toc -->

---

# Contents <!-- omit in toc -->

- [1. Introduction](#1-introduction)
- [2. Formal Representation of solving the problem](#2-formal-representation-of-solving-the-problem)
- [3. Framework Compartments](#3-framework-compartments)
  - [3.1. Controller](#31-controller)
- [Usage of Frameworks](#usage-of-frameworks)

---

## 1. Introduction

- Performance is reduced due to scripting languages
  - This is because it is an external client
  - Increases the space and time complexity
- All the code is finally converted to C/C++ code
- Best performance is achieved using C/C++

## 2. Formal Representation of solving the problem

1. Study the H/W
2. Map it to the discreet structure
3. Apply DAA to follow what the strategy is
4. Use appropriate Data Structures
5. Write the solution

## 3. Framework Compartments

1. Client
   1. Browser
2. Server
   1. Section 1
      1. Controller
   2. Section 2
      1. Entity
      2. Interface
      3. Service / Business Logic
3. Cloud
   1. Database
   2. etc.

- These are the level of abstractions in any framework
- This is achieved using various design patterns
- There is no tight coupling in Section 2, but no one can enter as design patterns are used

### 3.1. Controller

- Checks whether the request is legal
- It has inbuilt security checking methods

## Usage of Frameworks

- Very little effort for the developer
- Annotations are used in order to create new objects, meaning no one knows where the object instance is created

```
All frameworks use the principle of non dependability
```

- Developers have no access to any business logic, thus no control on the code, i.e. system has control