# BACE Processor Design

This repository contains the implementation and documentation of the BACE processor designed as 
part of the course CE222 - Computer Organization and Assembly Language.

## Project Overview

The project entails the design and construction of a functional Central Processing Unit (CPU) 
with a well-defined instruction set. The primary focus is on developing the bus structure, 
Arithmetic Logic Unit (ALU), Control Unit (CU), and other critical components of the processor. 
The BACE processor is an enhanced version of the Basic Computer, with additional features and an 
increased instruction set.

## Table of Contents

- [Abstract](#abstract)
- [Objectives](#objectives)
- [Theoretical Background](#theoretical-background)
- [Design and Implementation](#design-and-implementation)
  - [Bus Structure](#bus-structure)
  - [Arithmetic Logic Unit (ALU)](#arithmetic-logic-unit-alu)
  - [Control Unit (CU)](#control-unit-cu)
  - [Registers and Memory Configuration](#registers-and-memory-configuration)
- [Instruction Set](#instruction-set)
- [Conclusion](#conclusion)

## Abstract

The report follows a structured approach to design a functional CPU, detailing the bus 
structure, ALU, and CU, along with the necessary registers and memory configurations. It also 
includes a comprehensive instruction set for the BACE processor, explaining the purpose and 
theoretical background of each component. Enhancements over the Basic Computer, such as an 
improved ALU and an expanded instruction set, are thoroughly discussed.

## Objectives

The main objectives of the BACE processor design are:
- Data Transfer and Communication
- Short-Term and Long-Term Data Storage
- Data Processing
- Data Control Function

## Theoretical Background

The BACE processor is based on the Von Neumann Architecture, which stores data and instructions 
in the same memory medium. This design choice was made for its simplicity in designing, 
modeling, and implementation.

## Design and Implementation

### Bus Structure

The BACE processor employs a 24-bit common bus structure, enabling efficient data transfer 
between different components. The bus design reduces the need for direct connections between 
individual registers, saving circuitry and simplifying the overall design.

### Arithmetic Logic Unit (ALU)

The ALU performs basic arithmetic and logical operations, including addition, subtraction, 
increment, decrement, and various logical functions. It includes a look-ahead circuit for 
parallel carry generation and propagation, enhancing the efficiency of arithmetic operations.

### Control Unit (CU)

The CU orchestrates the operations of the CPU by directing the flow of data between the 
processor's components. It is designed with a hierarchical structure, detailing the 
functionality of each subcomponent.

### Registers and Memory Configuration

The processor includes multiple registers connected to the common bus. The design facilitates 
efficient data movement and storage, with specific registers dedicated to different functions 
such as data processing, short-term storage, and input/output operations.

## Instruction Set

The BACE processor's instruction set is defined using octal codes for simplicity and ease of 
representation. The instruction set includes memory-reference instructions, input/output 
instructions, and various other operations critical for CPU functionality.

| Symbol | Octal Code (I = 0) | Octal Code (I = 1) | Description |
|--------|--------------------|--------------------|-------------|
| SUM    | 00xxxxxx           | 40xxxxxx           | Add content of memory to accumulator. |
| DIF    | 01xxxxxx           | 41xxxxxx           | Subtract content of memory from 
accumulator. |
| GOTO   | 02xxxxxx           | 42xxxxxx           | Jumps/branches execution to a specified 
point. |
| CALL   | 03xxxxxx           | 43xxxxxx           | Calling subroutines in the program. |
| WMA    | 04xxxxxx           | 44xxxxxx           | Load content into accumulator from memory. 
|
| WAM    | 05xxxxxx           | 45xxxxxx           | Store content into memory from accumulator. 
|
| AND    | 06xxxxxx           | 46xxxxxx           | AND memory with accumulator. |
| OR     | 07xxxxxx           | 47xxxxxx           | OR memory with accumulator. |
| XOR    | 10xxxxxx           | 50xxxxxx           | XOR memory with accumulator. |
| NAND   | 11xxxxxx           | 51xxxxxx           | NAND memory with accumulator. |
| NOR    | 12xxxxxx           | 52xxxxxx           | NOR memory with accumulator. |

## Conclusion

The BACE processor design provides a comprehensive framework for understanding and implementing 
a functional CPU with an expanded instruction set and enhanced capabilities. This project lays 
the groundwork for further exploration and optimization of processor design in the field of 
computer organization and assembly language.

## Authors

- Muhammad Farae
- Uzair Rahman

## Acknowledgments

We extend our gratitude to the faculty of Computer Science & Engineering at Ghulam Ishaq Khan 
Institute of Engineering Sciences and Technology for their guidance and support throughout this 
project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

