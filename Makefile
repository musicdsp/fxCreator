
###############################################################################
### Some Preject properties :                                               ###
###############################################################################

# group name or constructor ... (no dot, no MAJ no Numerical char)
PROJECT_VENDOR=heeroyui
# Binary name ... (no dot, no MAJ no Numerical char)
PROJECT_NAME=fxcreator

USER_PACKAGES=$(shell pwd)/jni/

# include basic makefile for EWOL 
include $(shell pwd)/../ewol/Build/Makefile.mk

