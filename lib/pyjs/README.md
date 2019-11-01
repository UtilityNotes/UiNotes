# PyJS
Allows you to run JS in Python

This is made for UiNotes, you would need to edit code to make it work for your project

## Usage
```python
import js

def main():
  # Print title of page example
  title = js.run("document.title")
  print(title)
```

# Functions
These functions can currently return numbers (as longs), booleans, and strings

## js.run()
Executes the string inside run(). Will return 0 if it can't return anything else.

# Objects
