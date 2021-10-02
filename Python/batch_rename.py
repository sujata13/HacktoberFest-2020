import os

# put folder path here to rename
# this will rename all files starting from 1 and so on with maintaing sequence
folderPath = r'E:\ongoing\jc\trending'
filenumber = 1
# dont forget to add extension
for filename in os.listdir(folderPath):
	os.rename(folderPath +'\\' + filename, folderPath + '\\' +str(filenumber)+'.jpg')
	filenumber +=1
