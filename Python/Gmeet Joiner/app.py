import time
from tkinter import *
from functools import partial
from tkinter import messagebox
import os
from main import start, web
import threading

root = Tk()
canvas = Canvas(root)

uname = StringVar()
password = StringVar()
saveLogin = BooleanVar()
login_page_dict = {}
log = StringVar()
log_updater = threading.Thread()


def update_log():
    global log
    while True:
        temp = open("logs.log", 'r')
        log_concat = ""
        for i in temp.readlines():
            log_concat += i
        log.set(log_concat)
        temp.close()
        root.update_idletasks()
        time.sleep(1)


def destroy(elem):
    for k in elem.keys():
        elem[k].grid_remove()


def delete_login():
    os.remove("login.save")
    login_page()


def submit():
    global log, log_updater, log_label
    if saveLogin.get():
        with open("login.save", 'w+') as file:
            file.write(str(uname.get()) + "\n")
            file.write(str(password.get()))
    destroy(login_page_dict)
    log = "Initiating service.\n"
    log_label = Label(root, text=log)
    log_label.grid(row=0, column=1)
    log_updater = threading.Thread(target=update_log, daemon=True)
    log_updater.start()
    start.start()


def validate():
    if str(uname.get()) == "" or str(password.get()) == "":
        messagebox.showerror(title="Empty fields", message="Enter the details")
    else:
        submit()


validate = partial(validate)


def login_page():
    login_page_dict["reg"] = Label(root, text="Register number")
    login_page_dict["reg"].grid(row=0)
    login_page_dict["reg_ent"] = Entry(root, textvariable=uname)
    login_page_dict["reg_ent"].grid(row=0, column=1, padx=20, pady=10)
    login_page_dict["pass"] = Label(root, text="Password")
    login_page_dict["pass"].grid(row=1)
    login_page_dict["pass_ent"] = Entry(root, textvariable=password)
    login_page_dict["pass_ent"].grid(row=1, column=1)
    login_page_dict["submit"] = Button(root, text="Submit", command=validate)
    login_page_dict["submit"].grid(row=2, column=1, pady=10)
    login_page_dict["save_login"] = Checkbutton(root, text="Save login", variable=saveLogin)
    login_page_dict["save_login"].grid(row=3, column=3)


def quit():
    web.close()
    exit(0)


if os.path.exists("login.save"):
    log_label = Label(root, textvariable=log)
    log_label.grid(row=0, column=1)
    threading.Thread(target=update_log, daemon=True).start()
    start.start()
else:
    login_page()

menu = Menu(root)
root.config(menu=menu)
filemenu = Menu(menu)
menu.add_cascade(label="FIle", menu=filemenu)
filemenu.add_command(label="Forget login", command=delete_login)
filemenu.add_separator()
filemenu.add_command(label="Exit", command=quit)

root.mainloop()
