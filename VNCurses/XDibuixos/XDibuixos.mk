##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=XDibuixos
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses
ProjectPath            :=/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/XDibuixos
IntermediateDirectory  :=../build-$(ConfigurationName)/XDibuixos
OutDir                 :=../build-$(ConfigurationName)/XDibuixos
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Oscar
Date                   :=11/10/21
CodeLitePath           :=/home/oscar/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)XCURSES $(PreprocessorSwitch)PDCURSES 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)XCurses 
ArLibs                 :=  "XCurses" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS := -include ../src/pch.h -g -O0 -Wall $(Preprocessors)
CFLAGS   := -include ../src/pch.h -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/XDibuixos/up_src_DBInit.c$(ObjectSuffix) ../build-$(ConfigurationName)/XDibuixos/up_src_DBMain.c$(ObjectSuffix) ../build-$(ConfigurationName)/XDibuixos/up_src_pch.c$(ObjectSuffix) ../build-$(ConfigurationName)/XDibuixos/up_src_DBpresen.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/XDibuixos/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/XDibuixos"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/XDibuixos"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/XDibuixos/.d:
	@mkdir -p "../build-$(ConfigurationName)/XDibuixos"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/XDibuixos/up_src_DBInit.c$(ObjectSuffix): ../src/DBInit.c ../build-$(ConfigurationName)/XDibuixos/up_src_DBInit.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/DBInit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_DBInit.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/XDibuixos/up_src_DBInit.c$(DependSuffix): ../src/DBInit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/XDibuixos/up_src_DBInit.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/XDibuixos/up_src_DBInit.c$(DependSuffix) -MM ../src/DBInit.c

../build-$(ConfigurationName)/XDibuixos/up_src_DBInit.c$(PreprocessSuffix): ../src/DBInit.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/XDibuixos/up_src_DBInit.c$(PreprocessSuffix) ../src/DBInit.c

../build-$(ConfigurationName)/XDibuixos/up_src_DBMain.c$(ObjectSuffix): ../src/DBMain.c ../build-$(ConfigurationName)/XDibuixos/up_src_DBMain.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/DBMain.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_DBMain.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/XDibuixos/up_src_DBMain.c$(DependSuffix): ../src/DBMain.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/XDibuixos/up_src_DBMain.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/XDibuixos/up_src_DBMain.c$(DependSuffix) -MM ../src/DBMain.c

../build-$(ConfigurationName)/XDibuixos/up_src_DBMain.c$(PreprocessSuffix): ../src/DBMain.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/XDibuixos/up_src_DBMain.c$(PreprocessSuffix) ../src/DBMain.c

../build-$(ConfigurationName)/XDibuixos/up_src_pch.c$(ObjectSuffix): ../src/pch.c ../build-$(ConfigurationName)/XDibuixos/up_src_pch.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/pch.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_pch.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/XDibuixos/up_src_pch.c$(DependSuffix): ../src/pch.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/XDibuixos/up_src_pch.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/XDibuixos/up_src_pch.c$(DependSuffix) -MM ../src/pch.c

../build-$(ConfigurationName)/XDibuixos/up_src_pch.c$(PreprocessSuffix): ../src/pch.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/XDibuixos/up_src_pch.c$(PreprocessSuffix) ../src/pch.c

../build-$(ConfigurationName)/XDibuixos/up_src_DBpresen.c$(ObjectSuffix): ../src/DBpresen.c ../build-$(ConfigurationName)/XDibuixos/up_src_DBpresen.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/DBpresen.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_DBpresen.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/XDibuixos/up_src_DBpresen.c$(DependSuffix): ../src/DBpresen.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/XDibuixos/up_src_DBpresen.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/XDibuixos/up_src_DBpresen.c$(DependSuffix) -MM ../src/DBpresen.c

../build-$(ConfigurationName)/XDibuixos/up_src_DBpresen.c$(PreprocessSuffix): ../src/DBpresen.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/XDibuixos/up_src_DBpresen.c$(PreprocessSuffix) ../src/DBpresen.c


-include ../build-$(ConfigurationName)/XDibuixos//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


