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
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/BaseMenu.o \
	${OBJECTDIR}/Course.o \
	${OBJECTDIR}/CourseMenu.o \
	${OBJECTDIR}/Database.o \
	${OBJECTDIR}/MainMenu.o \
	${OBJECTDIR}/Person.o \
	${OBJECTDIR}/Professor.o \
	${OBJECTDIR}/ProfessorMenu.o \
	${OBJECTDIR}/Secretary.o \
	${OBJECTDIR}/Student.o \
	${OBJECTDIR}/StudentMenu.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/newsimpletest.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_2_cpp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_2_cpp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_2_cpp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/BaseMenu.o: BaseMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BaseMenu.o BaseMenu.cpp

${OBJECTDIR}/Course.o: Course.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Course.o Course.cpp

${OBJECTDIR}/CourseMenu.o: CourseMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CourseMenu.o CourseMenu.cpp

${OBJECTDIR}/Database.o: Database.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Database.o Database.cpp

${OBJECTDIR}/MainMenu.o: MainMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MainMenu.o MainMenu.cpp

${OBJECTDIR}/Person.o: Person.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Person.o Person.cpp

${OBJECTDIR}/Professor.o: Professor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Professor.o Professor.cpp

${OBJECTDIR}/ProfessorMenu.o: ProfessorMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProfessorMenu.o ProfessorMenu.cpp

${OBJECTDIR}/Secretary.o: Secretary.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Secretary.o Secretary.cpp

${OBJECTDIR}/Student.o: Student.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Student.o Student.cpp

${OBJECTDIR}/StudentMenu.o: StudentMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StudentMenu.o StudentMenu.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/BaseMenu_nomain.o: ${OBJECTDIR}/BaseMenu.o BaseMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BaseMenu.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BaseMenu_nomain.o BaseMenu.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/BaseMenu.o ${OBJECTDIR}/BaseMenu_nomain.o;\
	fi

${OBJECTDIR}/Course_nomain.o: ${OBJECTDIR}/Course.o Course.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Course.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Course_nomain.o Course.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Course.o ${OBJECTDIR}/Course_nomain.o;\
	fi

${OBJECTDIR}/CourseMenu_nomain.o: ${OBJECTDIR}/CourseMenu.o CourseMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CourseMenu.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CourseMenu_nomain.o CourseMenu.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CourseMenu.o ${OBJECTDIR}/CourseMenu_nomain.o;\
	fi

${OBJECTDIR}/Database_nomain.o: ${OBJECTDIR}/Database.o Database.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Database.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Database_nomain.o Database.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Database.o ${OBJECTDIR}/Database_nomain.o;\
	fi

${OBJECTDIR}/MainMenu_nomain.o: ${OBJECTDIR}/MainMenu.o MainMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MainMenu.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MainMenu_nomain.o MainMenu.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MainMenu.o ${OBJECTDIR}/MainMenu_nomain.o;\
	fi

${OBJECTDIR}/Person_nomain.o: ${OBJECTDIR}/Person.o Person.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Person.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Person_nomain.o Person.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Person.o ${OBJECTDIR}/Person_nomain.o;\
	fi

${OBJECTDIR}/Professor_nomain.o: ${OBJECTDIR}/Professor.o Professor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Professor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Professor_nomain.o Professor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Professor.o ${OBJECTDIR}/Professor_nomain.o;\
	fi

${OBJECTDIR}/ProfessorMenu_nomain.o: ${OBJECTDIR}/ProfessorMenu.o ProfessorMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ProfessorMenu.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProfessorMenu_nomain.o ProfessorMenu.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ProfessorMenu.o ${OBJECTDIR}/ProfessorMenu_nomain.o;\
	fi

${OBJECTDIR}/Secretary_nomain.o: ${OBJECTDIR}/Secretary.o Secretary.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Secretary.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Secretary_nomain.o Secretary.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Secretary.o ${OBJECTDIR}/Secretary_nomain.o;\
	fi

${OBJECTDIR}/Student_nomain.o: ${OBJECTDIR}/Student.o Student.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Student.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Student_nomain.o Student.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Student.o ${OBJECTDIR}/Student_nomain.o;\
	fi

${OBJECTDIR}/StudentMenu_nomain.o: ${OBJECTDIR}/StudentMenu.o StudentMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/StudentMenu.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StudentMenu_nomain.o StudentMenu.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/StudentMenu.o ${OBJECTDIR}/StudentMenu_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -Wall -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
