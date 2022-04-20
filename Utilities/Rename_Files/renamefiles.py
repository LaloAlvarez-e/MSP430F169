import os
import argparse

#absolute path of a file
currentFilePathName = r""
newFilePathName = r""


def main():
    errorCode = 0
    FilesRename = 0
    
    argParser = argparse.ArgumentParser(description= "Rename Files")
    argParser.add_argument("-p","--path", help= "Path of the files to rename")
    argParser.add_argument("-w","--word", help= "Word to Replace")
    argParser.add_argument("-r","--replace", help= "Replace Word")
    
    arguments = argParser.parse_args()
    pathDirFiles = arguments.path
    WordToReplace = arguments.word
    ReplaceWord = arguments.replace
    
    isPathDirValid = os.path.isdir(pathDirFiles)
    if isPathDirValid is True:
        print ("Directories names in progress..")
        FilesRename = 0;
        for path, subdirs, files in os.walk(pathDirFiles):
            for folder in subdirs:
                value = folder.find(WordToReplace);
                if value != -1:
                    FilesRename = FilesRename + 1;
                    newFileName = folder.replace(str(WordToReplace),str(ReplaceWord))
                    newPathFile = os.path.join(path, newFileName)
                    pathFile = os.path.join(path, folder)
                    os.rename(pathFile, newPathFile)
                    print(newPathFile)
        print ("Directories rename completed, Directories rename {} -- Successfull".format(FilesRename))
                    
                
        print ("Files names in progress..")
        FilesRename = 0;
        for path, subdirs, files in os.walk(pathDirFiles):
            for filename in files:
                value = filename.find(WordToReplace);
                if value != -1:
                    FilesRename = FilesRename + 1;
                    newFileName = filename.replace(str(WordToReplace),str(ReplaceWord))
                    newPathFile = os.path.join(path, newFileName)
                    pathFile = os.path.join(path, filename)
                    newFile = open(newPathFile, 'w')
                    with open(pathFile, 'r+') as file:
                        #read file
                        file_source = file.read()
                        #replace '' with '' in the file
                        replace_string = file_source.replace(WordToReplace, ReplaceWord)
                        #save output
                        newFile.write(replace_string)
                    os.remove(pathFile)
                    print(newPathFile)
                    
        print ("Files rename completed, Files rename {} -- Successfull".format(FilesRename))
    else:
        errorCode = 2
        print ("Dir Path is invalid")
    


if __name__ == "__main__":
    main()