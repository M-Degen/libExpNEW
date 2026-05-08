####################################################################################################
#
# Makefile for MinGw 
# (c) Copyright by Hydac System GmbH, all rights reserved
#
# PROJECT: 		Emulation platform
# Hardware: 	Windows
#
# FILE VERSION INFORMATION:
#	$Filename:	pc_compiler_setting.mak
#   $Version:	3.0 
#   $Date:		16.12.2019
#
####################################################################################################
SHELL=cmd.exe

####################################################################################################
# General path setting
####################################################################################################
include env/general_setting.mk

####################################################################################################
# Tools for the complete projekt
####################################################################################################
export CC           = $(MINGW_PATH)\bin\gcc
export CPP          = $(MINGW_PATH)\bin\g++

####################################################################################################
# Flags for Assembler, Compiler and Linker for the complete projekt
# For verification if the linker flags are really passed to the linker use the linker option -v and
# compare the specified flags.
####################################################################################################
export WARNINGS     = 
export AS_FLAGS     =
export CC_FLAGS     = 
export LINKER_FLAGS = 
