import requests
import re

class scrapeSteam:
    def __init__(self, link):
        self.pattern = "(https?://)?[a-zA-Z.]+\.[a-zA-z]+/app/([0-9]+)/.+"
        self.idPattern = r"\2"
        self.gameID = re.sub(self.pattern, self.idPattern, link)
        self.url = "https://store.steampowered.com/api/appdetails?appids="+self.gameID+"&cc=in"
        self.headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.71 Safari/537.36'}
        self.page = requests.get(self.url, headers=self.headers)
        self.data = self.page
        self.data = self.data.json()

    def getGameName(self):
        name = str(self.data[self.gameID]['data']['name'])
        
        print(name)

        return name
    
    def getGamePrice(self):
        if(self.data[self.gameID]['data']['is_free'] == True):
            print("The game is Free/Free to Play!")

            return -1.0
        else:
            price = float(self.data[self.gameID]['data']['price_overview']['final'])
            price /= 100

            print(price)

            return price

# - Object creation example - #
scrape = scrapeSteam("https://store.steampowered.com/app/489830/The_Elder_Scrolls_V_Skyrim_Special_Edition/")
scrape.getGameName()
scrape.getGamePrice()
# - Object creation example - #