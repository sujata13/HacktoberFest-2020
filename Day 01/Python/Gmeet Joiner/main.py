import os

from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
import time
from datetime import datetime
import win32api
from win10toast import ToastNotifier
import ctypes
import threading

notifier = ToastNotifier()
chrome_options = webdriver.ChromeOptions()
# self.chrome_options.binary_location = environ.get("GOOGLE_CHROME_BIN")
# chrome_options.add_argument("--headless")
chrome_options.add_argument("--disable-dev-shm-usage")
chrome_options.set_capability("useAutomationExtension", False)
chrome_options.add_argument("--disable-gpu")
chrome_options.add_argument("--no-sandbox")
# chrome_options.add_argument("user-agent=[Chrome/80.0.3987.116]")
chrome_options.add_argument("user-data-dir=selenium")
chrome_options.add_argument("use-fake-ui-for-media-stream")

web = webdriver.Chrome("D:/chromedriver.exe", options=chrome_options)

button_xpath = "/html[1]/body[1]/div[3]/div[2]/main[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/table[1]/tbody[1]/tr[placeholder]/td[4]/a[1]"
time_xpath = "/html[1]/body[1]/div[3]/div[2]/main[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/table[1]/tbody[1]/tr[placeholder]/td[3]/strong[1]"
join_xpath = "//span[contains(text(),'Ask to join')]"
camera_xpath = "//div[@class='IYwVEf HotEze nAZzG']//div[@class='oTVIqe BcUQQ']//*[local-name()='svg']"
mic_xpath = "//div[@class='IYwVEf HotEze uB7U9e nAZzG']//div[@class='oTVIqe BcUQQ']//*[local-name()='svg']"
class_xpath = "/html[1]/body[1]/div[3]/div[2]/main[1]/div[1]/div[1]/div[2]/div[1]/div[1]/div[1]/table[1]/tbody[1]/tr[1]/td[2]"

date = ""
href = ""
class_name = ""
log = ""


def start_class():
    ctypes.windll.user32.MessageBoxW(0, f"{class_name} => {href}", "Class will start shortly", 64)


def join_class(href):
    global log
    log += "Joining class" + "\n"
    print("Joining class")
    web.get(href)
    notifier.show_toast(class_name, href, duration=10, callback_on_click=start_class)
    for j in range(10):  # Trying to turn of camera and mic
        try:
            web.find_element_by_xpath(camera_xpath).click()
            web.find_element_by_xpath(mic_xpath).click()
        except NoSuchElementException:
            if j == 9:
                log += f"Could'nt turn off camera and mic" + "\n"
                print(f"Could'nt turn off camera and mic")

    for k in range(5):  # Trying to join the class
        try:
            web.find_element_by_xpath(join_xpath).click()
            log += "Waiting for the current class to finish." + "\n"
            print("Waiting for the current class to finish.")
            time.sleep(50 * 60)
        except NoSuchElementException:
            log += f"Error in joining the meet: {href}" + "\n"
            print(f"Error in joining the meet: {href}")
            time.sleep(2)


def start():
    with open("logs.log", 'w+') as file:
        file.write("Initiating service.\n")
    global log
    with open("login.save", 'r') as file:
        login_info = file.readlines()
        print(login_info)
        web.get("#your link")

        # Login to https://online.karunya.edu/oauth/login?access=student
        web.find_element_by_xpath("//input[@id='inputEmail']").send_keys(login_info[0].split("\n"))
        web.find_element_by_xpath("//input[@id='inputPassword']").send_keys(login_info[1])
        web.find_element_by_xpath("//button[@class='btn btn-block btn-primary']").click()
        time.sleep(3)
        entries = int(web.find_element_by_xpath("//div[@id='dataTable_info']").text.split(" ")[-2])

    for i in range(1, entries + 1):  # get info from the site
        try:
            class_name = web.find_element_by_xpath(class_xpath).text
            href = web.find_element_by_xpath(button_xpath.replace("placeholder", str(i))).get_attribute("href")
            date = web.find_element_by_xpath(time_xpath.replace("placeholder", str(i))).text
        except NoSuchElementException:
            log += "Something's wrong on getting info from #your link" + "\n"
            print("Something's wrong on getting info from #your link")
            continue

        date = datetime.strptime(date, '%d-%m-%Y %H:%M %p')
        current_date = datetime.strptime(time.strftime('%d-%m-%Y %H:%M'), '%d-%m-%Y %H:%M')
        diff = date - current_date
        minutes = divmod(diff.seconds, 60)
        print(class_name, "=>", minutes[0], "minutes", minutes[1], f"seconds --- [{diff}]")

        print(minutes)
        if minutes[0] <= 5:  # Open class link
            log += "Rushing to join!" + "\n"
            print("Rushing to join!")
            join_class(href)
        elif minutes[0] > 5:
            log += f"Will join in the last 5 min's. Waiting for {minutes[0] - 2} minutes" + "\n"
            print("Will join in the last 5 min's. Waiting for", minutes[0] - 2, "minutes")
            time.sleep((minutes[0] - 2) * 60)
            join_class(href)

    # web.close()


start = threading.Thread(target=start, daemon=True)


def logger():
    global log

    while True:
        with open("logs.log", 'r') as fileR:
            file_cont = fileR.readlines()
        with open("logs.log", 'a') as file:
            if file_cont[-1].strip("\n") != log.strip("\n"):
                file.write(log)
        time.sleep(1)


main_log_thread = threading.Thread(target=logger, daemon=True)
main_log_thread.start()

