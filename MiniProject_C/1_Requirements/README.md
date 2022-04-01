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
  - [Ybus] is formed by computing {[A]T * Yprim}*A

These functions can be easily executed in MATLAB code with functions that are in-built. But this application gives an overall idea of what goes on behind those functions and how they are called over and over within a program.

