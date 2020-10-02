from bs4 import BeautifulSoup
import requests
import re

class scrapeAmazon:
    def __init__(self, link):
        self.pattern = "((https?://)?(w{3})?\.[a-zA-Z]+\.[a-zA-z]+/[a-zA-Z0-9-]+/dp/[a-zA-Z0-9]+)/.+"
        self.shortenURL = r"\1"
        self.mainURL = re.sub(self.pattern, self.shortenURL, link)
        if not re.search("https?://.+", self.mainURL):
            self.mainURL = "https://" + self.mainURL
        #print(self.mainURL)
        self.headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.71 Safari/537.36'}
        self.url = self.mainURL
        self.page = requests.get(self.url, headers=self.headers)


    def getPrice(self):
        soup = BeautifulSoup(self.page.content, "lxml")

        if(str(soup.find(id="priceblock_ourprice")) == "None"):
            data = soup.find(id="priceblock_dealprice").getText()
        else:
            data = soup.find(id="priceblock_ourprice").getText()

        price = ''.join(i for i in data if i.isdigit())

        price = int(price)
        price /= 100

        print(price)

        return price

    def getProductName(self):
        soup = BeautifulSoup(self.page.content, "lxml")
        
        name = soup.find(id="productTitle").getText()

        name = name.strip()

        print(name)

        return name

# - Object creation example - #
scrape = scrapeAmazon("https://www.amazon.in/dp/B07XK8PLQT/ref=s9_acsd_al_bw_c2_x_3_i?pf_rd_m=A1K21FY43GMZF8&pf_rd_s=merchandised-search-2&pf_rd_r=HJX6BXAXE57AK7QY885W&pf_rd_t=101&pf_rd_p=d96f6e5b-f0ca-4db6-8252-4b7026d037bf&pf_rd_i=21563464031")
scrape.getProductName()
scrape.getPrice()
# - Object creation example - #