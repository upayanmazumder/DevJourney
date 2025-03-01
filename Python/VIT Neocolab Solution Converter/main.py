import pyperclip
import tkinter as tk
from tkinter import scrolledtext

def convert_to_markdown(message: str) -> str:
    lines = message.split("\n")
    markdown_lines = []
    
    for line in lines:
        line = line.strip()
        
        if line.startswith("Single File Programming Question"):
            markdown_lines.append(f"# {line}")
        elif line.startswith("Problem Statement"):
            markdown_lines.append(f"## {line}")
        elif line.startswith("Input format") or line.startswith("Output format") or \
             line.startswith("Code constraints") or line.startswith("Sample test cases"):
            markdown_lines.append(f"### {line}")
        elif line.startswith("Input ") or line.startswith("Output "):
            markdown_lines.append(f"#### {line}")
        else:
            markdown_lines.append(line)
    
    return "\n".join(markdown_lines)

def process_text():
    message = text_area.get("1.0", tk.END).strip()
    markdown_text = convert_to_markdown(message)
    pyperclip.copy(markdown_text)
    result_area.delete("1.0", tk.END)
    result_area.insert(tk.END, markdown_text)
    status_label.config(text="Markdown copied to clipboard!")

# GUI setup
root = tk.Tk()
root.title("Markdown Converter")

label = tk.Label(root, text="Enter your message:")
label.pack()

text_area = scrolledtext.ScrolledText(root, wrap=tk.WORD, width=60, height=10)
text_area.pack()

convert_button = tk.Button(root, text="Convert to Markdown", command=process_text)
convert_button.pack()

status_label = tk.Label(root, text="")
status_label.pack()

result_label = tk.Label(root, text="Converted Markdown:")
result_label.pack()

result_area = scrolledtext.ScrolledText(root, wrap=tk.WORD, width=60, height=10)
result_area.pack()

root.mainloop()
