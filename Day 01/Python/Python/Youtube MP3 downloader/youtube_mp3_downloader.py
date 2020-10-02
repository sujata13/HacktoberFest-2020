import subprocess
from youtube_dl import YoutubeDL
import time


folder = input("Specify folder for downloads")    # prompt user to specify folder in which to put the downloads

# allow the user to download multiple videos without having to close and re-rerun the script
while True:

    url = input("Enter url to video: ")    # prompt userto enter video url

    subprocess.call(
        ['youtube-dl', '-x', '--audio-format', 'mp3', 
        '--prefer-ffmpeg', url, '-o', folder+'%(title)s.mp3']
    )

    resp = input("Would you like to download another audio file? Y/N: ")

    # terminate loop and exit script
    if resp.lower() == 'n':
        print("Thank you for using our Youtube mp3 downloader!")
        print("Now exiting ...")
        time.sleep(1)
        break
