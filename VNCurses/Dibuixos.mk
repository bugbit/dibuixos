##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Dibuixos
ConfigurationName      :=Debug
WorkspacePath          :=/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses
ProjectPath            :=/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
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
OutputFile             :=$(IntermediateDirectory)/X$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)XCURSES 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Dibuixos.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)XCurses 
ArLibs                 :=  "XCurses" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=  -g -O3 -Wall -include src/pch.h $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_DBInit.c$(ObjectSuffix) $(IntermediateDirectory)/src_DBMain.c$(ObjectSuffix) $(IntermediateDirectory)/src_pch.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_DBInit.c$(ObjectSuffix): src/DBInit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_DBInit.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_DBInit.c$(DependSuffix) -MM src/DBInit.c
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/DBInit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_DBInit.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_DBInit.c$(PreprocessSuffix): src/DBInit.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_DBInit.c$(PreprocessSuffix) src/DBInit.c

$(IntermediateDirectory)/src_DBMain.c$(ObjectSuffix): src/DBMain.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_DBMain.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_DBMain.c$(DependSuffix) -MM src/DBMain.c
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/DBMain.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_DBMain.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_DBMain.c$(PreprocessSuffix): src/DBMain.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_DBMain.c$(PreprocessSuffix) src/DBMain.c

$(IntermediateDirectory)/src_pch.c$(ObjectSuffix): src/pch.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_pch.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_pch.c$(DependSuffix) -MM src/pch.c
	$(CC) $(SourceSwitch) "/home/oscar/proyectos/oscar/retro/dibuixos/VNCurses/src/pch.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_pch.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_pch.c$(PreprocessSuffix): src/pch.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_pch.c$(PreprocessSuffix) src/pch.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


