import tkinter as tk
from tkinter import *
from tkinterweb import HtmlFrame

global window
window = tk.Tk()
global history
history = []
global urlglo
urlglo = ""

class URL:
    def __init__(self):
        self.urlwin = tk.Tk()
        self.urlwin.geometry('660x70+100+70')
        self.urlwin.title("Enter new URL")
        self.urlwin.resizable(0, 0)

        self.temp = StringVar(self.urlwin)

        self.qLabel = Label(self.urlwin, text="Query: ", font=('arial', 12))
        self.qLabel.grid(row=0, column=1)

        self.textBox = Entry(self.urlwin, textvariable=self.temp, width=45, font=('arial', 10))
        self.textBox.grid(padx=10, row=0, column=2)

        self.enterButton = Button(self.urlwin, text="Enter", font=('arial', 10), command=self.directToURL)
        self.enterButton.grid(row=0, column=3, padx=5)

        self.urlwin.mainloop()

    def directToURL(self):
        urlglo = self.temp.get()
        bframe.loadPageFromInput(urlglo)

class ObMenu:
    def __init__(self):
        self.mymenu = Menu(window)
        self.options = Menu(self.mymenu)
        window.config(menu=self.mymenu)

        self.mymenu.add_cascade(label="Actions", menu=self.options)
        self.options.add_command(label="Back", command=self.headBack)
        self.options.add_command(label="Forward", command=self.headForward)
        self.options.add_command(label="Refresh", command=self.refresh)
        self.options.add_command(label="Go to different site", command=self.goToURL)

    def refresh(self):
        bframe.refreshPage(history[len(history)-1])

    def goToURL(self):
        temp = URL()

    def headBack(self):
        bframe.loadPageFromBack(history[len(history)-2])
        forHist.insert(0, history.pop(len(history)-1))

    def headForward(self):
        if len(forHist) > 0:
            url = forHist.pop(0)
            bframe.loadPageFromInput(url)

class BrowserFrame:
    def __init__(self):
        self.mmenu = ObMenu()
        self.frame = HtmlFrame(window)
        self.width = window.winfo_screenwidth()
        self.height = window.winfo_screenheight()
        window.geometry("%dx%d" % (self.width, self.height))
        self.loadPageInitial()
        self.frame.pack(fill="both", expand=True)

    def addToHistory(self, url):
        history.append(url)

    def refreshPage(self, url):
        self.frame.load_website(f"http://{url}")

    def loadPageFromInput(self, url):
        self.frame.load_website(f"http://{url}")

    def loadPageFromBack(self, url):
        self.frame.load_website(f"http://{url}")

    def loadPageInitial(self):
        self.frame.load_website(f"http://www.google.com")
        history.append(f"www.google.com")


global bframe
bframe = BrowserFrame()
global forHist
forHist = []


def geturl(url):
    if "http://" in url:
        url = url.replace("http://", "")
    bframe.addToHistory(url)
    bframe.loadPageFromInput(url)

bframe.frame.on_link_click(geturl)

def initialize():
    window.title("Browser")
    window.mainloop()

initialize()


