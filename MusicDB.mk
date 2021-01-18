##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=MusicDB
ConfigurationName      :=Release
WorkspacePath          :=/media/kronos/BKP/BackupImportant/DEVlocal/CPPWorkspace
ProjectPath            :=/media/kronos/BKP/BackupImportant/DEVlocal/CPPWorkspace/MusicDB
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=KronoS
Date                   :=11/04/20
CodeLitePath           :=/home/kronos/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="MusicDB.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/TrackParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/List_base.cpp$(ObjectSuffix) $(IntermediateDirectory)/Playlist.cpp$(ObjectSuffix) $(IntermediateDirectory)/ListIndex.cpp$(ObjectSuffix) 



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
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/TrackParser.cpp$(ObjectSuffix): TrackParser.cpp $(IntermediateDirectory)/TrackParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/kronos/BKP/BackupImportant/DEVlocal/CPPWorkspace/MusicDB/TrackParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TrackParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TrackParser.cpp$(DependSuffix): TrackParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TrackParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TrackParser.cpp$(DependSuffix) -MM TrackParser.cpp

$(IntermediateDirectory)/TrackParser.cpp$(PreprocessSuffix): TrackParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TrackParser.cpp$(PreprocessSuffix) TrackParser.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/kronos/BKP/BackupImportant/DEVlocal/CPPWorkspace/MusicDB/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/List_base.cpp$(ObjectSuffix): List_base.cpp $(IntermediateDirectory)/List_base.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/kronos/BKP/BackupImportant/DEVlocal/CPPWorkspace/MusicDB/List_base.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/List_base.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/List_base.cpp$(DependSuffix): List_base.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/List_base.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/List_base.cpp$(DependSuffix) -MM List_base.cpp

$(IntermediateDirectory)/List_base.cpp$(PreprocessSuffix): List_base.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/List_base.cpp$(PreprocessSuffix) List_base.cpp

$(IntermediateDirectory)/Playlist.cpp$(ObjectSuffix): Playlist.cpp $(IntermediateDirectory)/Playlist.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/kronos/BKP/BackupImportant/DEVlocal/CPPWorkspace/MusicDB/Playlist.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Playlist.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Playlist.cpp$(DependSuffix): Playlist.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Playlist.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Playlist.cpp$(DependSuffix) -MM Playlist.cpp

$(IntermediateDirectory)/Playlist.cpp$(PreprocessSuffix): Playlist.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Playlist.cpp$(PreprocessSuffix) Playlist.cpp

$(IntermediateDirectory)/ListIndex.cpp$(ObjectSuffix): ListIndex.cpp $(IntermediateDirectory)/ListIndex.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/kronos/BKP/BackupImportant/DEVlocal/CPPWorkspace/MusicDB/ListIndex.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ListIndex.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ListIndex.cpp$(DependSuffix): ListIndex.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ListIndex.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ListIndex.cpp$(DependSuffix) -MM ListIndex.cpp

$(IntermediateDirectory)/ListIndex.cpp$(PreprocessSuffix): ListIndex.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ListIndex.cpp$(PreprocessSuffix) ListIndex.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


