# Install using 'pip install --user pyttsx3'.
import pyttsx3 

# Install using 'pip install --user PyPDF2'.
import PyPDF2

book = open('your_pdf_name.pdf', 'rb')

pdfReader = PyPDF2.PdfFileReader(book)

pages = pdfReader.numPages #To check total number of pages in the pdf.

speaker = pyttsx3.init()

voices = speaker.getProperty('voices')

speaker.setProperty('voice', voices[1].id)
#You can add loop to play every page's audio or you can hard code the value of 'x'.
#Uncomment the next line if you want to use loop and indent the following lines respectively. 
#for x in range(pages):
page = pdfReader.getPage(x) # x here is the page number

text = page.extractText()

speaker.say(text)

speaker.runAndWait()