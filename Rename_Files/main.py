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
    print (pathDirFiles)
    print (WordToReplace)
    print (ReplaceWord)
    
    isPathDirValid = os.path.isdir(pathDirFiles)
    if isPathDirValid is True:
        print ("File names in progress..")
        for path, subdirs, files in os.walk(pathDirFiles):
            for filename in files:
                value = filename.find(WordToReplace);
                if value is not -1:
                    newFileName = filename.replace(str(WordToReplace),str(ReplaceWord))
                    pathFile = os.path.join(path, newFileName)
                    print(newFileName)
                    print(pathFile)
    else:
        errorCode = 2
        print ("Dir Path is invalid")
    
    errorString = "Successfull"
    if errorCode != 0:
        errorString = "Error"
    
    print ("File names completed, Files rename {} -- {}".format(FilesRename, errorString))


if __name__ == "__main__":
    main()