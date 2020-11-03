## do install SpeechRecognition (pip3 install SpeechRecognition)
## also install pyAudio (pip3 install PyAudio)

import speech_recognition as sr

r = sr.Recognizer()
with sr.Microphone() as source:
    print("Hello, please speak : ")
    audio = r.listen(source)

    try:
        text = r.recognize_google(audio)
        print("This is what you said : {}".format(text))
    except:
        print("Sorry please try again!")   
