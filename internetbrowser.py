import tkinter as tk
from tkinter import *
from tkinterweb import HtmlFrame

global window
window = tk.Tk()
global history
history = []

class BrowserFrame:
    def __init__(self):
        self.frame = HtmlFrame(window)
        self.width = window.winfo_screenwidth()
        self.height = window.winfo_screenheight()
        window.geometry("%dx%d" % (self.width, self.height))
        self.loadPageInitial("www.google.com")
        self.frame.pack(fill="both", expand=True)

        self.mymenu = Menu(window)
        self.options = Menu(self.mymenu)
        window.config(menu=self.mymenu)
        self.createMenu()

        self.temp = StringVar()

        self.qLabel = Label(self.urlwin, text="Query: ", font=('arial', 12))
        self.qLabel.grid(row=0, column=1)

        self.textBox = Entry(self.urlwin, textvariable=self.temp, width=45, font=('arial', 10))
        self.textBox.grid(padx=10, row=0, column=2)

        self.enterButton = Button(self.urlwin, text="Enter", font=('arial', 10), command=self.directToURL)
        self.enterButton.grid(row=0, column=3, padx=5)

        self.urlwin.mainloop()

    def createMenu(self):
        self.mymenu.add_cascade(label="Actions", menu=self.options)
        self.options.add_command(label="Back", command=self.headBack)
        self.options.add_command(label="Refresh", command=self.refresh)
        self.options.add_command(label="Go to different site", command=self.goToURL)

    def refresh(self):
        BrowserFrame.loadPageInitial()

    def openURL(self):
        self.urlwin = tk.Tk()
        self.urlwin.geometry('660x70+100+70')
        self.urlwin.title("Enter new URL")
        self.urlwin.resizable(0, 0)

        return self.directToURL()

    def goToURL(self):
        temp = self.openURL()
        url = temp.directToURL()
        return

    def headBack(self):
        self.frame.load_website(f"http://{history[len(history)-1]}")
        history.pop()

    def loadPageFromInput(self, url):
        self.frame.load_website(f"http://{url}")
        history.append(f"http://{url}")


    def loadPageInitial(self, url):
        self.frame.load_website(f"http://{url}")
        history.append(f"http://{url}")

    def directToURL(self):
        self.urlwin.quit()
        return self.textBox.get()

def initialize():
    bframe = BrowserFrame()
    window.title("Browser")
    window.mainloop()

initialize()


