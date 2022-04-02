# Requirements

## Introduction

YBUS matrix mostly used in load flow analysis of power system networks. YBUS is
a sparse matrix so it is very easy and convenient to analysis the network with minimal
time a memory of systems. YBUS can be constructed by two methods. 

They are
- Direct Inspection Method
- Singular transformation Method

### Direct Inspection Method

In Direct Inspection Method, YBUS can be constructed by directly using the network parameters values. The network is usually represented by its pi-model. The diagonal elements of YBUS matrix is sum of all admittances connected to particular node. Off-diagonal elements is equal to negative of admittances connected between two nodes. If there is no interconnection between two buses, then that particular element will be represented by zero. The condition for applying this method is there is no mutual coupling between the buses. If there is mutual coupling this method is not applicable, then we need go for Singular transformation Method

### Singular Transformation Method

With help of graph theory, the network is formedand bus incidence matrix is
formed for the same network[A]. Take transpose of [A]. Primitive impedance matrix[Z] is
formed from the network and primitive admittance matrix[y] is obtained by taking inverse
of primitive impedance matrix. The final Ybus can be obtained by multiplying transpose
of [A]^T*[Y]*[A]. The buses which have mutual impedances also solved by this method.

## Research

- Calculating Y bus matrix is a crucial part of power system analysis as it is the first step in analysing the large power networks in a simplest way. The singular transformation accomodates the possibility of mutual impedences contributing to the overall admittance of the system. The Y bus of a power system can be calculated in the following steps.

  - Get elemental impedance and mutual impedance (if any) from the user
  - Compute admittance of elements connected to the bus
  - Bus incidence matrix is formed from graph theory by checking the condition with
buses and element connections. The conditions are
    1) If element starting from the assign 1.If element ending in the bus assign -1.
    2) If there is no connection between buses assign 0.
  - Display the bus incidence matrix and its transpose
  - Fill the diagonal of a 2D matrix with elemental impedances and required offdiagonal elements with mutual impedances (if any)
  - Display bus primitive impedance matrix and primitive admittance matrix
  - [Ybus] is formed by computing {[A]^T * Yprim}*A

These functions can be easily executed in MATLAB code with functions that are in-built. But this application gives an overall idea of what goes on behind those functions and how they are called over and over within a program.

### Benefits

#### - Easy calculation of Y_bus
    Calculation of Y_bus is made easier in this program as it uses the fuctions and pointers to calculate the steps and have been reused within the program. The functions in this program can be reused across many programs for calculation of other power system parameters.

#### - Load Flow analysis
    This functions can be used accross various problems for load flow analysis with power systems and atrices of any order. The reusability of the code makes first time users understand how the operations in power flow ananlysis are repeated within processes and how admittance is the inverse impedence.

## Functions

  | Feature | Description 
  |---------|--------------------------------------------------------------------------------------------------------------------------------------------------------
  |  F1     | Calculates the bus admittance matrix using the number of buses, number of elements, starting bus and ending bus of the elemnets.
  |  F2     | Calculates the primitive impedence matrix using the primitive elements, and mutual impedence values
  |  F3     | Calculates the y_bus matrix by calculating determinant and cofactor matrix of primitive impedence 
  |  F4     | Performs matrix multiplication to calculate Y_Bus
  
## SWOT Analysis

### Who

    - Students trying to solve power flow analysis problems
    - Students who try to reuse code for various other methods of load flow analysis
    
### What

    - The hand calculations get a little too complicated when the bus system get larger and larger with matrix multiplications and debugging becomes tedius. This could be a go to for all sizes of matrices
    
### When

    - These methods will continue to remain true for generations to come whn it comes to analyzing power systems.
    
### Where

    -Engineering institutions, electrical projects, schools, Project development and many more.
    
### How

    - It only receives input in two places and does the rest of the calculations by itself.
    - Only the basic knowlege and data about buses, elements and impedences required.
    
## High Level Requirements

| ID | Description | Category |  
| ----- | ----- | ------- | 
| HLR01 | User should identify the buses, elements, starting and ending buses | Technical | 
| HLR02 | User should be able to calculate the bus incidence matrix and transpose | Technical |
| HLR03 | User to identify the primitive elements and calculate z bus | Technical | 
| HLR04 | User to calculate inverse of z bus, and find y bus | Technical |

## Low level requirements

| ID | Description | Category |  
| ----- | ----- | ------- | 
| LLR01 | The bus admittance matrix will be calculated using the number of buses, number of elements, starting bus and ending bus of the elemnets.| HLR01 | 
| LLR02 | User should be able to calculate the transpose of bus admittance matrix | HLR02 |
| LLR03 | User should be able to calculate the z bus | HLR03 | 
| LLR04 | User should be able to calculate inverse of z bus, and find y bus | HLR04 |
    
  
