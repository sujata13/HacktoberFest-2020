# Python script to lowercase letters in multiple text file in a folder


from itertools import chain
from glob import glob
import os

for filename in os.listdir(''):
		#Enter your folder directory
		with open(os.path.join('',filename),'r', encoding = 'utf-8') as f: #open in readonly mode
			text = f.read()
			text = text.lower()
			# Enter your output folder directory
			with open(os.path.join('',filename),'w', encoding = 'utf-8') as w:
				w.write(text)