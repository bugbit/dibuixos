##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Dibuixos
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses
ProjectPath            :=/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/Dibuixos
IntermediateDirectory  :=../build-$(ConfigurationName)/Dibuixos
OutDir                 :=../build-$(ConfigurationName)/Dibuixos
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)ncurses $(LibrarySwitch)ncurses 
ArLibs                 :=  "ncurses" "ncurses" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS := -include ../src/pch.h  $(Preprocessors)
CFLAGS   := -include ../src/pch.h -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Dibuixos/up_src_DBInit.c$(ObjectSuffix) ../build-$(ConfigurationName)/Dibuixos/up_src_DBMain.c$(ObjectSuffix) ../build-$(ConfigurationName)/Dibuixos/up_src_pch.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Dibuixos/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Dibuixos"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Dibuixos"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Dibuixos/.d:
	@mkdir -p "../build-$(ConfigurationName)/Dibuixos"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Dibuixos/up_src_DBInit.c$(ObjectSuffix): ../src/DBInit.c ../build-$(ConfigurationName)/Dibuixos/up_src_DBInit.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/DBInit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_DBInit.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Dibuixos/up_src_DBInit.c$(DependSuffix): ../src/DBInit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Dibuixos/up_src_DBInit.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Dibuixos/up_src_DBInit.c$(DependSuffix) -MM ../src/DBInit.c

../build-$(ConfigurationName)/Dibuixos/up_src_DBInit.c$(PreprocessSuffix): ../src/DBInit.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Dibuixos/up_src_DBInit.c$(PreprocessSuffix) ../src/DBInit.c

../build-$(ConfigurationName)/Dibuixos/up_src_DBMain.c$(ObjectSuffix): ../src/DBMain.c ../build-$(ConfigurationName)/Dibuixos/up_src_DBMain.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/DBMain.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_DBMain.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Dibuixos/up_src_DBMain.c$(DependSuffix): ../src/DBMain.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Dibuixos/up_src_DBMain.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Dibuixos/up_src_DBMain.c$(DependSuffix) -MM ../src/DBMain.c

../build-$(ConfigurationName)/Dibuixos/up_src_DBMain.c$(PreprocessSuffix): ../src/DBMain.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Dibuixos/up_src_DBMain.c$(PreprocessSuffix) ../src/DBMain.c

../build-$(ConfigurationName)/Dibuixos/up_src_pch.c$(ObjectSuffix): ../src/pch.c ../build-$(ConfigurationName)/Dibuixos/up_src_pch.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/pch.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_src_pch.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Dibuixos/up_src_pch.c$(DependSuffix): ../src/pch.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Dibuixos/up_src_pch.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Dibuixos/up_src_pch.c$(DependSuffix) -MM ../src/pch.c

../build-$(ConfigurationName)/Dibuixos/up_src_pch.c$(PreprocessSuffix): ../src/pch.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Dibuixos/up_src_pch.c$(PreprocessSuffix) ../src/pch.c


-include ../build-$(ConfigurationName)/Dibuixos//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


