import UiNotes

def main():
    title = UiNotes.runJS("document.title")
    print("The current file is " + title)
    UiNotes.runJS("$('body').append(\"<div id='title' style='width:calc(100% - 8px);height:64px;box-shadow:0 1px 3px rgba(0,0,0,.8);border-radius:4px;padding:4px'></div>\")")
    UiNotes.runJS("$('#title').append(\"<h1 style='text-align:center;color:rgba(255,255,255,.8)''>The Menu</h1>\")")
