#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Bfs.o \
	${OBJECTDIR}/Connectivity.o \
	${OBJECTDIR}/Dfs.o \
	${OBJECTDIR}/Dijkstra.o \
	${OBJECTDIR}/Graph.o \
	${OBJECTDIR}/GraphList.o \
	${OBJECTDIR}/GraphMatrix.o \
	${OBJECTDIR}/InputHandler.o \
	${OBJECTDIR}/relatorio2-estudo1-questao1.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f7 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f6

# C Compiler Flags
CFLAGS=`cppunit-config --cflags` 

# CC Compiler Flags
CCFLAGS=`cppunit-config --cflags` 
CXXFLAGS=`cppunit-config --cflags` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`cppunit-config --libs` `cppunit-config --libs`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f8

${TESTDIR}/TestFiles/f8: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f8 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Bfs.o: Bfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Bfs.o Bfs.cpp

${OBJECTDIR}/Connectivity.o: Connectivity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Connectivity.o Connectivity.cpp

${OBJECTDIR}/Dfs.o: Dfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Dfs.o Dfs.cpp

${OBJECTDIR}/Dijkstra.o: Dijkstra.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Dijkstra.o Dijkstra.cpp

${OBJECTDIR}/Graph.o: Graph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Graph.o Graph.cpp

${OBJECTDIR}/GraphList.o: GraphList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/GraphList.o GraphList.cpp

${OBJECTDIR}/GraphMatrix.o: GraphMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/GraphMatrix.o GraphMatrix.cpp

${OBJECTDIR}/InputHandler.o: InputHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/InputHandler.o InputHandler.cpp

${OBJECTDIR}/relatorio2-estudo1-questao1.o: relatorio2-estudo1-questao1.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/relatorio2-estudo1-questao1.o relatorio2-estudo1-questao1.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/bfstestclass1.o ${TESTDIR}/tests/bfstestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/dfstestclass1.o ${TESTDIR}/tests/dfstestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/dijkstratestclass1.o ${TESTDIR}/tests/dijkstratestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/inputhandlertestclass1.o ${TESTDIR}/tests/inputhandlertestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/outputinfotestclass1.o ${TESTDIR}/tests/outputinfotestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/testesbasicostestclass.o ${TESTDIR}/tests/testesbasicostestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/testesbasicoscompesotestclass1.o ${TESTDIR}/tests/testesbasicoscompesotestrunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/bfstestclass1.o: tests/bfstestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/bfstestclass1.o tests/bfstestclass1.cpp


${TESTDIR}/tests/bfstestrunner1.o: tests/bfstestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/bfstestrunner1.o tests/bfstestrunner1.cpp


${TESTDIR}/tests/dfstestclass1.o: tests/dfstestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/dfstestclass1.o tests/dfstestclass1.cpp


${TESTDIR}/tests/dfstestrunner1.o: tests/dfstestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/dfstestrunner1.o tests/dfstestrunner1.cpp


${TESTDIR}/tests/dijkstratestclass1.o: tests/dijkstratestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/dijkstratestclass1.o tests/dijkstratestclass1.cpp


${TESTDIR}/tests/dijkstratestrunner.o: tests/dijkstratestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/dijkstratestrunner.o tests/dijkstratestrunner.cpp


${TESTDIR}/tests/inputhandlertestclass1.o: tests/inputhandlertestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/inputhandlertestclass1.o tests/inputhandlertestclass1.cpp


${TESTDIR}/tests/inputhandlertestrunner1.o: tests/inputhandlertestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/inputhandlertestrunner1.o tests/inputhandlertestrunner1.cpp


${TESTDIR}/tests/outputinfotestclass1.o: tests/outputinfotestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/outputinfotestclass1.o tests/outputinfotestclass1.cpp


${TESTDIR}/tests/outputinfotestrunner1.o: tests/outputinfotestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/outputinfotestrunner1.o tests/outputinfotestrunner1.cpp


${TESTDIR}/tests/testesbasicostestclass.o: tests/testesbasicostestclass.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/testesbasicostestclass.o tests/testesbasicostestclass.cpp


${TESTDIR}/tests/testesbasicostestrunner.o: tests/testesbasicostestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/testesbasicostestrunner.o tests/testesbasicostestrunner.cpp


${TESTDIR}/tests/testesbasicoscompesotestclass1.o: tests/testesbasicoscompesotestclass1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/testesbasicoscompesotestclass1.o tests/testesbasicoscompesotestclass1.cpp


${TESTDIR}/tests/testesbasicoscompesotestrunner1.o: tests/testesbasicoscompesotestrunner1.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/testesbasicoscompesotestrunner1.o tests/testesbasicoscompesotestrunner1.cpp


${OBJECTDIR}/Bfs_nomain.o: ${OBJECTDIR}/Bfs.o Bfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Bfs.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Bfs_nomain.o Bfs.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Bfs.o ${OBJECTDIR}/Bfs_nomain.o;\
	fi

${OBJECTDIR}/Connectivity_nomain.o: ${OBJECTDIR}/Connectivity.o Connectivity.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Connectivity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Connectivity_nomain.o Connectivity.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Connectivity.o ${OBJECTDIR}/Connectivity_nomain.o;\
	fi

${OBJECTDIR}/Dfs_nomain.o: ${OBJECTDIR}/Dfs.o Dfs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Dfs.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Dfs_nomain.o Dfs.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Dfs.o ${OBJECTDIR}/Dfs_nomain.o;\
	fi

${OBJECTDIR}/Dijkstra_nomain.o: ${OBJECTDIR}/Dijkstra.o Dijkstra.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Dijkstra.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Dijkstra_nomain.o Dijkstra.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Dijkstra.o ${OBJECTDIR}/Dijkstra_nomain.o;\
	fi

${OBJECTDIR}/Graph_nomain.o: ${OBJECTDIR}/Graph.o Graph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Graph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Graph_nomain.o Graph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Graph.o ${OBJECTDIR}/Graph_nomain.o;\
	fi

${OBJECTDIR}/GraphList_nomain.o: ${OBJECTDIR}/GraphList.o GraphList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/GraphList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/GraphList_nomain.o GraphList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/GraphList.o ${OBJECTDIR}/GraphList_nomain.o;\
	fi

${OBJECTDIR}/GraphMatrix_nomain.o: ${OBJECTDIR}/GraphMatrix.o GraphMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/GraphMatrix.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/GraphMatrix_nomain.o GraphMatrix.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/GraphMatrix.o ${OBJECTDIR}/GraphMatrix_nomain.o;\
	fi

${OBJECTDIR}/InputHandler_nomain.o: ${OBJECTDIR}/InputHandler.o InputHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/InputHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/InputHandler_nomain.o InputHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/InputHandler.o ${OBJECTDIR}/InputHandler_nomain.o;\
	fi

${OBJECTDIR}/relatorio2-estudo1-questao1_nomain.o: ${OBJECTDIR}/relatorio2-estudo1-questao1.o relatorio2-estudo1-questao1.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/relatorio2-estudo1-questao1.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/relatorio2-estudo1-questao1_nomain.o relatorio2-estudo1-questao1.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/relatorio2-estudo1-questao1.o ${OBJECTDIR}/relatorio2-estudo1-questao1_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f8

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
